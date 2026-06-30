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
	void solve(vector<ll>& heights)
	{
		int n = heights.size();
		vector<ll> cw(n), ccw(n);
		for (int i = 0; i < n; i++)
		{
			cw[i] = 0;
			ll currentMax = 0;
			for (int j = 1; j < n; j++)
			{
				int u = (i + j - 1) % n;
				int v = (i + j) % n;
				int edge = u;
				if (j == 1)
				{
					currentMax = heights[edge];
				}
				else
				{
					currentMax = max(currentMax, heights[edge]);
				}
				cw[v] = currentMax;
			}

			ccw[i] = 0;
			currentMax = 0;
			for (int j = 1; j < n; j++)
			{
				int v = (i - j + n) % n;
				int edge = v;
				if (j == 1)
				{
					currentMax = heights[edge];
				}
				else
				{
					currentMax = max(currentMax, heights[edge]);
				}
				ccw[v] = currentMax;
			}

			ll totalVolume = 0;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					totalVolume += min(cw[j], ccw[j]);
				}
			}
			cout << totalVolume << " ";
		}
		cout << "\n";
	}
};

int main()
{
	fastIo();
	int t;
	Solution sol;
	vector<ll> heights;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		heights.clear();
		heights.resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> heights[j];
		}
		sol.solve(heights);
	}

	return 0;
}