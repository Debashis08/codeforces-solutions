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
	void Solve(vector<int>& vec)
	{
		int n = vec.size();
		bool flag = false;

		for (int i = 0; i < n; i++)
		{
			if (vec[vec[vec[i]]] == i)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
};

int main()
{
	FastIO();

	long n;
	cin >> n;
	vector<int> vec;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x - 1);
	}
	
	Solution solution;
	solution.Solve(vec);

	return 0;
}