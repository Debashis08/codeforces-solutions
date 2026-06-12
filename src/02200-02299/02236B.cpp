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
	void isPossibleToWin(ll n, ll k, string s)
	{
		vector<ll> chainOnes(k, 0);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '1')
			{
				chainOnes[i % k]++;
			}
		}

		bool isPossible = true;
		for (auto& it : chainOnes)
		{
			if (it % 2 != 0)
			{
				isPossible = false;
				break;
			}
		}

		if (isPossible)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
};

int main()
{
	fastIo();
	int t;
	ll n, k;
	string s;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		cin >> s;
		sol.isPossibleToWin(n, k, s);
	}
	return 0;
}