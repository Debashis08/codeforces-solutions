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
	void solve(int n)
	{
		vector<int> result;
		// Construct the array
		// Hardcoded edge cases
		if (n == 2)
		{
			result = { 1, 2, 2, 1, 1, 2, 1, 2 };
		}
		else if (n == 3)
		{
			result = { 1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3 };
		}
		else
		{
			// part-1
			for (int i = 1; i <= n; i++)
			{
				result.push_back(i);
				result.push_back(i);
			}

			// part-2
			for (int i = 2; i <= n; i++)
			{
				result.push_back(i);
			}
			result.push_back(1);

			int next = 2;
			for (int i = 1; i <= n; i++)
			{
				if (i == n - 2)
				{
					result.push_back(1);
				}
				else
				{
					result.push_back(next);
					next++;
				}
			}
		}

		// Print the array.
		for (int i=0;i<result.size();i++)
		{
			cout << result[i] << (i == result.size() - 1 ? "" : " ");
		}
		cout << "\n";
	}
};

int main()
{
	fastIo();
	int t;
	int n;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		sol.solve(n);
	}

	return 0;
}