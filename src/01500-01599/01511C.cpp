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
	int n, q;
	cin >> n >> q;
	vector<int> cards(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}
	int x = 0;
	while (q--)
	{
		// Take the query color
		cin >> x;

		// Find in the cards with minimum index
		int p = find(cards.begin(), cards.end(), x) - cards.begin();

		// Print the position
		cout << p + 1 << " ";

		// Take the card and place it on top of the deck
		rotate(cards.begin(), cards.begin() + p, cards.begin() + p + 1);
	}

	return 0;
}