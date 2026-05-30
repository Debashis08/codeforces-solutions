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
	long long gcd(long long a, long long b)
	{
		while (b)
		{
			a %= b;
			swap(a, b);
		}
		return a;
	}

	long long lcm(long long a, long long b)
	{
		return a / this->gcd(a, b) * b;
	}

	long long power(long long base, long long exp, long long mod = MOD)
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
	int findMaxFriends(string u, int n, int x, int s)
	{
		vector<int> table(x + 1, -1);
		table[0] = 0;
		for (int i = 0; i < n; i++)
		{
			char c = u[i];
			vector<int> nextTable = table;
			for (int j = 0; j <= x; j++)
			{
				if (table[j] == -1)
				{
					continue;
				}
				if ((c == 'I' || c == 'A') && j + 1 <= x)
				{
					if (table[j] + 1 > nextTable[j + 1])
					{
						nextTable[j + 1] = table[j] + 1;
					}
				}
				if ((c == 'E' || c == 'A') && j > 0)
				{
					if (table[j] < j * s)
					{
						if (table[j] + 1 > nextTable[j])
						{
							nextTable[j] = table[j] + 1;
						}
					}
				}
			}
			table = nextTable;
		}

		int maxSeated = INT_MIN;
		for (int j = 0; j <= x; j++)
		{
			if (table[j] > maxSeated)
			{
				maxSeated = table[j];
			}
		}

		return maxSeated;
	}
};

int main()
{
	fastIo();
	int t;
	cin >> t;
	int n, x, s;
	string u;
	Solution sol;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> x >> s;
		cin >> u;
		cout << sol.findMaxFriends(u, n, x, s) << endl;
	}

	return 0;
}