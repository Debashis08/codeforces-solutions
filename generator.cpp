#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

// Helper function to format the 5-digit folder name (e.g., 02200-02299)
string getFolderName(int problemNum)
{
    int lower = (problemNum / 100) * 100;
    int upper = lower + 99;

    stringstream ss;
    ss << setfill('0') << setw(5) << lower << "-"
       << setfill('0') << setw(5) << upper;
    return ss.str();
}

// Helper function to copy file contents
bool copyTemplate(const string& sourcePath, const string& destPath)
{
    ifstream source(sourcePath, ios::binary);
    if (!source)
    {
        cerr << "[ERROR] Could not open template file: " << sourcePath << "\n";
        return false;
    }

    ofstream dest(destPath, ios::binary);
    if (!dest)
    {
        cerr << "[ERROR] Could not create destination file: " << destPath << "\n";
        return false;
    }

    dest << source.rdbuf();
    return true;
}

int main()
{
    cout << "========================================\n";
    cout << "      Codeforces File Generator         \n";
    cout << "========================================\n\n";

    string inputId;
    cout << "Enter Problem ID (e.g., 282A, 1057A, 2232C1): ";
    if (!(cin >> inputId))
    {
        cerr << "[ERROR] Invalid input.\n";
        return 1;
    }

    // 1. Parse the input into numeric part and string suffix
    int firstNonDigit = 0;
    while (firstNonDigit < inputId.length() && isdigit(inputId[firstNonDigit]))
    {
        firstNonDigit++;
    }

    if (firstNonDigit == 0)
    {
        cerr << "[ERROR] Invalid input. Problem ID must start with a number.\n";
        return 1;
    }

    int problemNum = stoi(inputId.substr(0, firstNonDigit));
    string suffix = inputId.substr(firstNonDigit);

    // 2. Calculate the 5-digit padded folder name using the helper
    string folderName = getFolderName(problemNum);
    
    // 3. Calculate the 5-digit padded file name
    stringstream fileSs;
    fileSs << setfill('0') << setw(5) << problemNum << suffix;
    string problemName = fileSs.str();

    // Define target directories
    fs::path srcDir = fs::path("src") / folderName;
    fs::path testDir = fs::path("tests") / folderName;

    // Define target files
    fs::path cppFile = srcDir / (problemName + ".cpp");
    fs::path txtFile = testDir / (problemName + ".txt");

    // 4. Create directories if they don't exist
    try
    {
        fs::create_directories(srcDir);
        fs::create_directories(testDir);
    }
    catch (const fs::filesystem_error& e)
    {
        cerr << "[ERROR] Failed to create directories: " << e.what() << "\n";
        return 1;
    }

    // 5. Check if files already exist to prevent accidental overwriting
    if (fs::exists(cppFile) || fs::exists(txtFile))
    {
        cout << "[WARNING] Files for Problem " << problemName << " already exist!\n";
        cout << "Overwrite? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            cout << "Operation aborted.\n";
            return 0;
        }
    }

    // 6. Copy templates
    bool cppSuccess = copyTemplate("template.cpp", cppFile.string());
    bool txtSuccess = copyTemplate("template.txt", txtFile.string());

    // 7. Output results
    cout << "\n----------------------------------------\n";
    if (cppSuccess && txtSuccess)
    {
        cout << "[SUCCESS] Files generated successfully!\n";
        cout << "Source : " << cppFile.string() << "\n";
        cout << "Test   : " << txtFile.string() << "\n";
    }
    else
    {
        cout << "[FAILED] Make sure 'template.cpp' and 'template.txt' exist in the root directory.\n";
    }
    cout << "----------------------------------------\n";

    return 0;
}