/*
Tags

constructive algorithms
games
greedy

----------------------------------------------------------------------------------------------------------------------------

Problem Description

Binary String Battle

Alice and Bob are playing a game with a binary string s of length n and an integer k (where 1 <= k < n).

Alice wins if she can transform all characters of s into zeroes. If Alice cannot achieve this in a finite number of moves, then Bob wins.

Players take turns starting with Alice:
- On Alice's turn, she can choose any subsequence of length k from s and set all characters in that subsequence to zero.
- On Bob's turn, he can choose any substring of length k from s and set all characters in that substring to one.

Alice wins if the string consists entirely of zeroes at any point during the game, including between turns.

Determine the winner assuming both players play optimally.

Input:
- The first line contains an integer t (1 <= t <= 10^4) - the number of test cases.
- For each test case:
  - The first line contains two integers n and k (2 <= n <= 2*10^5 and 1 <= k < n).
  - The second line contains a binary string s of length n.

It is guaranteed that the total sum of n over all test cases does not exceed 2*10^5.

Output:
For each test case, print "Alice" if Alice wins with optimal play, or "Bob" if Bob wins with optimal play. You may print the output in any letter case, such as "alice", "ALICE", "aLiCe", etc.

Note:
- A subsequence is a set of characters from the string that do not need to be adjacent.
- A substring is a contiguous group of characters from the string.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

void FastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Solution
{
public:
	void Solve(int n, int k, string s)
	{
		int countOnes = 0;
		for (char c : s)
		{
			if (c == '1')
			{
				countOnes++;
			}
		}
		cout << (countOnes<=k || n<2*k ? "Alice" : "Bob") << endl;
	}
};

int main()
{
	FastIO();
	int t;
	cin >> t;
	Solution solution;

	int n, k;
	string s;

	while (t--)
	{
		cin >> n >> k >> s;
		solution.Solve(n, k, s);
	}

	return 0;
}