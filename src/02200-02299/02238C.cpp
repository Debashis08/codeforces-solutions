/*
Tags



----------------------------------------------------------------------------------------------------------------------------

Problem Description



*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <limits>
#include <iomanip>
#include <functional>
#include <cstring>
#include <climits>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

// Fast I/O
void fastIo()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Solution
{
private:
	ll gcd(ll a, ll b)
	{
		while (b)
		{
			a %= b;
			swap(a, b);
		}
		return a;
	}

	ll lcm(ll a, ll b)
	{
		return a / this->gcd(a, b) * b;
	}

	ll power(ll base, ll exp, ll mod = MOD)
	{
		ll result = 1;
		base %= mod;
		while (exp > 0)
		{
			if (exp & 1)
				result = result * base % mod;
			base = base * base % mod;
			exp >>= 1;
		}
		return result;
	}

public:
	void solve()
	{
		int n;
		cin >> n;
		
		vector<int> p(n + 1);
		vector<int> depth(n + 1, 0);
		vector<int> maxDepth(n + 1, 0);

		for (int i = 2; i <= n; i++)
		{
			cin >> p[i];
			depth[i] = depth[p[i]] + 1;
			maxDepth[i] = depth[i];
		}

		vector<int> max1(n + 1, -1);
		vector<int> max2(n + 1, -1);

		for (int i = n; i >= 2; i--)
		{
			int parent = p[i];
			int childMaxDepth = maxDepth[i];

			if (childMaxDepth > max1[parent])
			{
				max2[parent] = max1[parent];
				max1[parent] = childMaxDepth;
			}
			else if (childMaxDepth > max2[parent])
			{
				max2[parent] = childMaxDepth;
			}
			
			if (childMaxDepth > maxDepth[parent])
			{
				maxDepth[parent] = childMaxDepth;
			}
		}

		ll totalGuilds = n;

		for (int i = 1; i <= n; i++)
		{
			if (max2[i] != -1)
			{
				totalGuilds += (max2[i] - depth[i]);
			}
		}

		cout << totalGuilds << "\n";
	}
};

int main()
{
	fastIo();
	int t;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		sol.solve();
	}

	return 0;
}