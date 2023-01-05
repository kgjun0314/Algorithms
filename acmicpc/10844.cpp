#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const long long MOD = 1000000000LL;

long long dp[101][11];
long long N;
long long cnt = 0;

long long solve(long long n, long long i)
{
    if(dp[n][i] != -1)
    {
        return dp[n][i] % MOD;
    }
    if(n == 1)
    {
        return dp[n][i] = 1;
    }
    if(i == 0)
    {
        return dp[n][i] = solve(n - 1, i + 1) % MOD;
    }
    if(i == 9)
    {
        return dp[n][i] = solve(n - 1, i - 1) % MOD;
    }
    else
        return dp[n][i] = (solve(n - 1, i - 1) % MOD + solve(n - 1, i + 1) % MOD) % MOD;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    memset(dp, -1, sizeof(dp));
    
    for(long long i = 1; i <= 9; i++)
    {
        cnt += solve(N, i) % MOD;
        cnt = cnt % MOD;
    }

    cout << cnt % MOD << endl;
    return 0;
}