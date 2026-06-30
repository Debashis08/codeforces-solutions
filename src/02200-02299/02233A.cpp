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
#include <cmath>
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
	void findMinHours(int n, int x, int y, int z)
	{
		int drop = ceil((n+x+y-1) / (x + y));

		//drop case
		int pick = INT_MAX;
		int lines = z * x;
		if (n <= lines)
		{
			pick = ceil((n+x-1) / x);
		}
		else
		{
			int remainingLines = n - lines;
			int combinedSpeed = x + 10 * y;
			pick = z + ((remainingLines + combinedSpeed - 1) / combinedSpeed);
		}

		cout << min(drop, pick) << "\n";
	}
};

int main()
{
	fastIo();
	int t;
	int n, x, y, z;
	Solution sol;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> x >> y >> z;
		sol.findMinHours(n, x, y, z);
	}

	return 0;
}