/*
Tags



----------------------------------------------------------------------------------------------------------------------------

Problem Description



*/

#include <iostream>
#include <vector>
#include <string>
#include<algorithms>
#include<functional>
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
	void Solve(int n, int c, vector<int>& vec)
	{
		sort(vec.begin(), vec.end(),greater<int>());
	}
};

int main()
{
	FastIO();
    int t;
    cin>>t;
    int n,c;
    Solution solution;
    while(t--)
    {
        cin>>n>>c;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        solution.solve(n,c,vec);
    }

	return 0;
}