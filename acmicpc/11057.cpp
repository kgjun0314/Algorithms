#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define endl "\n";

long long N;
long long dp[1001][10];
long long ans = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int j = 0; j < 10; j++)
    {
        dp[1][j] = 1;
    }

    for (int i = 0; i <= 1000; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
        }
    }

    for (int j = 0; j < 10; j++)
    {
        ans = (ans + dp[N][j]) % 10007;
    }

    cout << ans % 10007 << endl;

    return 0;
}