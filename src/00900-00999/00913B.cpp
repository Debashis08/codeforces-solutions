/*
Tags



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
	ll binPow(ll base, ll exp, ll mod = MOD)
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
	void solve()
	{

	}
};

int main()
{
	fastIo();
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> deg(n);
	for (int i = 1; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
		deg[p[i]]++;
	}
	vector<int> leafChild(n);
	for (int i = 0; i < n; i++)
	{
		if (deg[i] == 0)
		{
			leafChild[p[i]]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (deg[i] > 0 && leafChild[i] < 3)
		{
			cout << "No" << "\n";
			return 0;
		}
	}

	cout << "Yes" << "\n";
	return 0;
}