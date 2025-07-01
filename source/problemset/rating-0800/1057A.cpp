/*
Problem Id = 1057A
Tags = #dfs
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

void FastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Solution
{
public:
	void Solve(int n, vector<int>& vec)
	{
		bool flag = false;
		int node = n;
		vector<int> res;
		while (flag == false)
		{
			if (node == 1)
			{
				flag = true;
			}
			res.push_back(node);
			node = vec[node];
		}
		for (int i = res.size() - 1; i >= 0; i--)
		{
			cout << res[i] << " ";
		}
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n + 1, -1);
	int x;
	vec[1] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x;
		vec[i + 2] = x;
	}
	vector<int> result;
	Solution solution;
	solution.Solve(n, vec);
}