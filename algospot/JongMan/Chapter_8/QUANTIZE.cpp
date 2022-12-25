#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = 987654321;
int C, n, s;
int A[101], pSum[101], pSqSum[101];
int dp[101][11];

void precalc()
{
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for(int i = 0; i < n; i++)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

int minError(int lo, int hi)
{
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	return sqSum - 2 * m * sum + m * m * (hi - lo + 1);
}

int quantize(int from, int parts)
{
	if(from == n)
	{
		return 0;
	}
	if(parts == 0)
	{
		return INF;
	}
	if(dp[from][parts] != -1)
	{
		return dp[from][parts];
	}
	dp[from][parts] = INF;
	for(int partSize = 1; from + partSize <= n; partSize++)
	{
		dp[from][parts] = min(dp[from][parts], minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	}
	return dp[from][parts];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C;

	while(C--)
	{
		cin >> n >> s;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		precalc();
		memset(dp, -1, sizeof(dp));
		cout << quantize(0, s) << endl;
	}

	return 0;
}