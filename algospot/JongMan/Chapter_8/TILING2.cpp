#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const long long MOD = 1000000007;
long long dp[200];
long long C, n;

long long tiling(long long width)
{
	if(width <= 1)
		return 1;
	if(dp[width] != -1)
		return dp[width];
	return dp[width] = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C;

	while(C--)
	{
		cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << tiling(n) << endl;
	}

	return 0;
}