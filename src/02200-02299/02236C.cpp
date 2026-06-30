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
	int findMinOperations(ll a, ll b, ll x)
	{
		if (a == b)
		{
			return 0;
		}
		
		vector<pair<ll, ll>> pathA;
		vector<pair<ll, ll>> pathB;
		ll currA = a;
		ll currB = b;
		ll opsACount = 0;
		ll opsBCount = 0;
		while (true)
		{
			pathA.push_back({ currA, opsACount });
			if (currA == 0)
			{
				break;
			}
			currA /= x;
			opsACount++;
		}

		while (true)
		{
			pathB.push_back({ currB, opsBCount });
			if (currB == 0)
			{
				break;
			}
			currB /= x;
			opsBCount++;
		}

		ll minOps = LLONG_MAX;
		for (auto& pa : pathA)
		{
			for (auto& pb : pathB)
			{
				ll currentOps = pa.second + pb.second + abs(pa.first - pb.first);
				minOps = min(minOps, currentOps);
			}
		}

		return minOps;
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
		ll a, b, x;
		cin >> a >> b >> x;
		int result = sol.findMinOperations(a, b, x);
		cout << result << "\n";
	}

	return 0;
}