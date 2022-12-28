#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const int MOD = 10*1000*1000;
int dp[101][101];
int n, C;

int poly(int n, int first)
{
	if(n == first)
	{
		return 1;
	}

	if(dp[n][first] != -1)
	{
		return dp[n][first];
	}

	dp[n][first] = 0;

	for(int second = 1; second <= n-first; second++)
	{
		dp[n][first] += ((second + first - 1) * poly(n - first, second)) % MOD;
		dp[n][first] %= MOD;
	}

	return dp[n][first];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C;

	while(C--)
	{
		int ans = 0;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			ans += poly(n, i);
			ans %= MOD;
		}
		cout << ans << endl;
	}

	return 0;
}