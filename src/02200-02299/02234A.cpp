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
	void solve(vector<int>& nums)
	{
		int n = nums.size();
		sort(nums.begin(), nums.end(), greater<int>());
		bool isValid = true;
		for (int i = 0; i < n - 2; i++)
		{
			if ((nums[i] % nums[i + 1]) != nums[i + 2])
			{
				isValid = false;
				break;
			}
		}

		if (isValid)
		{
			cout << nums[0] << " " << nums[1] << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
};

int main()
{
	fastIo();
	int t;
	Solution sol;
	vector<int> nums;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n,x;
		cin >> n;
		nums.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			nums.push_back(x);
		}
		sol.solve(nums);
	}

	return 0;
}