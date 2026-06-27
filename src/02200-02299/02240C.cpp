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
	void solve(vector<ll>& nums)
	{
		size_t n = nums.size();
		ll modValue = 998244353;
		ll sum = 0;
		ll nonZeroCount = 0;
		for (int i = 0; i < n; i++)
		{
			sum ^= nums[i];
			if (nums[i] > 0)
			{
				nonZeroCount++;
			}
		}

		if (nonZeroCount <= 1)
		{
			cout << 0 << "\n";
			return;
		}
		ll result = 0;
		if (sum == 0)
		{
			result = 1;
		}
		for (int i = 0; i < n; i++)
		{
			if (nums[i] > (nums[i] ^ sum))
			{
				result++;
			}
		}
		cout << (result % modValue) << "\n";
	}
};

int main()
{
	fastIo();
	int t, n;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<ll> nums(n);
		for (int j = 0; j < n; j++)
		{
			cin >> nums[j];
		}
		sol.solve(nums);
	}

	return 0;
}