#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

void FastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Solution
{
public:
	void Solve(int n)
	{
		cout << ((n % 4 == 0) ? "Bob" : "Alice") << endl;
	}
};

int main()
{
	FastIO();

	int t;
	cin >> t;
	Solution solution;

	while (t--)
	{
		int n;
		cin >> n;
		solution.Solve(n);
	}

	return 0;
}