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
const ll INF = 1e18;

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
	void solve(vector<int>& a, vector<int>&b, size_t n, int c)
	{
		int sumA = 0;
		int sumB = 0;
		for (int it : a)
		{
			sumA += it;
		}
		for (int it : b)
		{
			sumB += it;
		}
		if (sumA < sumB)
		{
			cout << -1 << "\n";
			return;
		}
		ll baseCost = sumA - sumB;
		ll noReorder = INF;
		ll reorder = INF;

		bool isOriginalOrderValid = true;
		for (size_t i = 0; i < n; i++)
		{
			if (a[i] < b[i])
			{
				isOriginalOrderValid = false;
				break;
			}
		}
		if (isOriginalOrderValid)
		{
			noReorder = baseCost;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		bool isSortedValid = true;
		for (size_t i = 0; i < n; i++)
		{
			if (a[i] < b[i])
			{
				isSortedValid = false;
				break;
			}
		}

		if (isSortedValid)
		{
			reorder = c + baseCost;
		}
		ll result = min(noReorder, reorder);
		if (result == INF)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << result << "\n";
		}
	}
};

int main()
{
	fastIo();
	int t, n, c;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> c;
		vector<int> a(n);
		vector<int> b(n);
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < n; j++)
		{
			cin >> b[j];
		}
		sol.solve(a, b, n, c);
	}

	return 0;
}