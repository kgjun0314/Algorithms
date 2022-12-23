#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int C, N;
int num;
int A[500];
int dp[500];

int lis(int start)
{
	if(dp[start] != -1)
	{
		return dp[start];
	}
	dp[start] = 1;
	for(int next = start + 1; next < N; next++)
	{
		if(A[start] < A[next])
			dp[start] = max(dp[start], 1 + lis(next));
	}
	return dp[start];
}

int main(void)
{
	cin >> C;
	while(C--)
	{
		cin >> N;
		memset(A, 0, sizeof(A));
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < N; i++)
		{
			cin >> num;
			A[i] = num;
		}
		int maxLen = 0;
		for(int begin = 0; begin < N; begin++)
		{
			maxLen = max(maxLen, lis(begin));
		}
		cout << maxLen << endl;
	}	
	return 0;
}