#include <iostream>
#include <vector>
#include <string>
#include<climits>
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
		vector<int> vec(n + 1, 0), prefixVec(n + 1, INT_MAX), suffixVec(n + 2, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> vec[i];
			prefixVec[i] = min(prefixVec[i - 1], vec[i]);
		}

		for (int i = n; i >= 1; i--)
		{
			suffixVec[i] = max(suffixVec[i + 1], vec[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			cout << (vec[i] == prefixVec[i] || vec[i] == suffixVec[i] ? 1 : 0);
		}
		cout << endl;
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