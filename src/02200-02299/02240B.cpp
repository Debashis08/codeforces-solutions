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

const int MOD = 998244353;

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
				result = (result * base) % mod;
			base = (base * base) % mod;
			exp >>= 1;
		}
		return result;
	}

public:
	void solve(ll n, ll m, ll r, ll c)
	{
		ll totalVariables = n * m;
		ll equations = (n - r + 1) * (m - c + 1);
		ll freeVariables = totalVariables - equations;

		ll exp = freeVariables % (MOD-1);
		ll result = this->power(2, exp);
		cout << result << "\n";
	}
};

int main()
{
	fastIo();
	int t;
	ll n, m, r, c;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> r >> c;
		sol.solve(n, m, r, c);
	}
	return 0;
}