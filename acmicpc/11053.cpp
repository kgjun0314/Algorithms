#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> A(1001);
int dp[1001];
int maxLen;

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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    int maxLen = 0;
	for(int begin = 0; begin < N; begin++)
	{
		maxLen = max(maxLen, lis(begin));
	}
	cout << maxLen << endl;

    return 0;
}