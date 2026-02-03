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
	void Solve(int n, int j, int k)
	{
		int maxStrength = 0;
		vector<int> vec(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> vec[i];
			maxStrength = max(maxStrength, vec[i]);
		}
		cout << ((k > 1  || vec[j]==maxStrength)?"YES":"NO") << endl;
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
		int n, j, k;
		cin >> n >> j >> k;
		solution.Solve(n, j, k);
	}

	return 0;
}