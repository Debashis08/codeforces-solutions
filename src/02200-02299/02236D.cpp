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
	void isPossibleToWin(vector<int>& nums, int k)
	{
		int n = nums.size();
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			mp[nums[i]]++;
		}
		vector<int> v;
		vector<int> c;
		for (auto& [value, count] : mp)
		{
			v.push_back(value);
			c.push_back(count);
		}
		int m = v.size();
		int lastFalse = -1;
		bool egorCanWin = false;
		for (int i = m - 1; i >= 0; i--)
		{
			bool lose = false;

			if (lastFalse != -1 && v[lastFalse] - v[i] <= k) {
				lose = true;
			}

			bool win;
			if (lose) {
				win = true;
			}
			else {
				win = (c[i] % 2 == 0);
			}

			if (!win) {
				lastFalse = i;
			}

			if (win) {
				egorCanWin = true;
			}
		}

		if (egorCanWin)
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
	int n, k;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		vector<int> nums(n);
		for (int j = 0; j < n; j++)
		{
			cin >> nums[j];
		}
		sol.isPossibleToWin(nums, k);
	}
	return 0;
}