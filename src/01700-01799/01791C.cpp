/*
Tags

two-pointer

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
	int findShortestPossibleString(string s, int size)
	{
		int left = 0;
		int right = size - 1;
		while (left <= right)
		{
			if (s[left] != s[right])
			{
				size -= 2;
				left++;
				right--;
			}
			else
			{
				break;
			}
		}
		return size;
	}
};

int main()
{
	fastIo();
    int t,n;
	string s;
	cin >> t;
	Solution sol;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> s;
		cout << sol.findShortestPossibleString(s, n) << endl;
	}

	return 0;
}