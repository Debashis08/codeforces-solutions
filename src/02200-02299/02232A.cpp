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
	int minGroupCalls(vector<int>& vec)
	{
		int n = vec.size();
		int minCalls = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			int targetLocation = vec[i];
			int leftCount = 0;
			int rightCount = 0;

			for (int j = 0; j < n; j++)
			{
				if (vec[j] < targetLocation)
				{
					leftCount++;
				}
				else if(vec[j]>targetLocation)
				{
					rightCount++;
				}
			}

			int callCount = max(leftCount, rightCount);
			minCalls = min(minCalls, callCount);
		}
		return minCalls;
	}
};

int main()
{
	fastIo();
    int t,n;
    cin >> t;
	Solution sol;
	int x;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> vec;
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			vec.push_back(x);
		}
		cout << sol.minGroupCalls(vec) << endl;
	}

	return 0;
}