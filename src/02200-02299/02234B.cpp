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
	void solve(ll n)
	{
		vector<ll> possiblePalindromes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22 };
		for (ll a : possiblePalindromes)
		{
			if (a <= n && a % 12 == n % 12)
			{
				ll b = n - a;
				cout << a << " " << b << "\n";
				return;
			}
		}
		cout << -1 << "\n";
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
		ll n;
		cin >> n;
		sol.solve(n);
	}

	return 0;
}