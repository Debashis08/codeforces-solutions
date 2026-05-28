/*
Tags

two-pointers

----------------------------------------------------------------------------------------------------------------------------

Problem Description

Sereja and Dima play a game. The rules of the game are very simple. The players have n cards in a row. Each card contains a number, all numbers on the cards are distinct.
The players take turns, Sereja moves first. During his turn a player can take one card: either the leftmost card in a row, or the rightmost one.
The game ends when there is no more cards. The player who has the maximum sum of numbers on his cards by the end of the game, wins.
Sereja and Dima are being greedy. Each of them chooses the card with the larger number during his move.
Inna is a friend of Sereja and Dima. She knows which strategy the guys are using, so she wants to determine the final score, given the initial state of the game. Help her.

Input
The first line contains integer n (1 ≤ n ≤ 1000) — the number of cards on the table. The second line contains space-separated numbers on the cards from left to right.
The numbers on the cards are distinct integers from 1 to 1000.

Output
On a single line, print two integers. The first number is the number of Sereja's points at the end of the game, the second number is the number of Dima's points at the end of the game.

Examples
InputCopy
4
4 1 2 10
OutputCopy
12 5
InputCopy
7
1 2 3 4 5 6 7
OutputCopy
16 12
Note
In the first sample Sereja will take cards with numbers 10 and 2, so Sereja's sum is 12. Dima will take cards with numbers 4 and 1, so Dima's sum is 5.

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
	void findPoints(vector<int>& vec)
	{
		int sereja = 0, dima = 0;
		int left = 0;
		int right = vec.size() - 1;
		int turn = 1;
		while (left <= right)
		{
			if (turn % 2 == 0)
			{
				if (vec[left] > vec[right])
				{
					dima += vec[left];
					left++;
				}
				else
				{
					dima += vec[right];
					right--;
				}
			}
			else
			{
				if (vec[left] > vec[right])
				{
					sereja += vec[left];
					left++;
				}
				else
				{
					sereja += vec[right];
					right--;
				}
			}
			turn++;
		}

		cout << sereja << " " << dima;
	}
};

int main()
{
	fastIo();

	int n;
	cin >> n;
	int x;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	Solution sol;
	sol.findPoints(vec);

	return 0;
}