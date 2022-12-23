#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int C, N, M;
int num;
int A[101], B[101];
int dp[101][101];

int lis(int startA, int startB)
{
	if(dp[startA + 1][startB + 1] != -1)
	{
		return dp[startA + 1][startB + 1];
	}
	dp[startA + 1][startB + 1] = 2;
	long long a = (startA == -1 ? NEGINF : A[startA]);
	long long b = (startB == -1 ? NEGINF : B[startB]);
	long long maxElement = max(a, b);
	for(int nextA = startA + 1; nextA < N; nextA++)
	{
		if(maxElement < A[nextA])
			dp[startA + 1][startB + 1] = max(dp[startA + 1][startB + 1], 1 + lis(nextA, startB));
	}
	for(int nextB = startB + 1; nextB < M; nextB++)
	{
		if(maxElement < B[nextB])
			dp[startA + 1][startB + 1] = max(dp[startA + 1][startB + 1], 1 + lis(startA, nextB));
	}
	return dp[startA + 1][startB + 1];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C;
	while(C--)
	{
		cin >> N >> M;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < N; i++)
		{
			cin >> num;
			A[i] = num;
		}
		for(int i = 0; i < M; i++)
		{
			cin >> num;
			B[i] = num;
		}
		cout << lis(-1, -1) -2 << endl;
	}	
	return 0;
}