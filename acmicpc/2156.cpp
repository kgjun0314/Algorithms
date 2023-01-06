#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10010];
int glass[10010];
int N, num;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        glass[i] = num;
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = glass[0];
    dp[1] = glass[0] + glass[1];
    dp[2] = max(glass[0], glass[1]) + glass[2];
    dp[2] = max(dp[2], dp[1]);

    for(int i = 3; i < N; i++)
    {
        dp[i] = max(dp[i - 3] + glass[i - 1] + glass[i], dp[i - 2] + glass[i]);
        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[N - 1] << endl;
    return 0;
}