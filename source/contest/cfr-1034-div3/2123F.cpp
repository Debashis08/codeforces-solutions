/*
Tags



----------------------------------------------------------------------------------------------------------------------------

Problem Description

Minimize Fixed Points

Time limit per test: 3 seconds
Memory limit per test: 256 megabytes

Call a permutation p of length n good if gcd(p[i], i) > 1 for all 2 <= i <= n.
Find a good permutation with the minimum number of fixed points across all good permutations of length n.
If there are multiple such permutations, print any of them.

Note:

- A permutation of length n is an array that contains every integer from 1 to n exactly once, in any order.
- gcd(x, y) denotes the greatest common divisor (GCD) of x and y.
- A fixed point of a permutation p is an index j (1 <= j <= n) such that p[j] == j.

Input
The first line contains an integer t (1 <= t <= 10^4) — the number of test cases.
Each of the next t lines contains one integer n (2 <= n <= 10^5) — the length of the permutation.
It is guaranteed that the sum of all n over all test cases does not exceed 10^5.

Output
For each test case, output on a single line a good permutation of length n with the minimum number of fixed points.


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

using namespace std;

const int MOD = 1e9 + 7;

// Fast I/O
void FastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Solution
{
private:
	long long GCD(long long a, long long b)
	{
		while (b)
		{
			a %= b;
			swap(a, b);
		}
		return a;
	}

	long long LCM(long long a, long long b)
	{
		return a / this->GCD(a, b) * b;
	}

	long long Power(long long base, long long exp, long long mod = MOD)
	{
		long long result = 1;
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
	void Solve()
	{
		int n;
		cin >> n;

	}
};

int main()
{
	FastIO();
	int t;
	cin >> t;
	Solution sol;
	while (t--)
	{
		sol.Solve();
	}

	return 0;
}