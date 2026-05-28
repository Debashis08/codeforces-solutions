#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

void fastIo()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Solution
{
public:
	void solve(int n)
	{
		cout << ((n % 4 == 0) ? "Bob" : "Alice") << endl;
	}
};

int main()
{
	fastIo();

	int t;
	cin >> t;
	Solution solution;

	while (t--)
	{
		int n;
		cin >> n;
		solution.solve(n);
	}

	return 0;
}