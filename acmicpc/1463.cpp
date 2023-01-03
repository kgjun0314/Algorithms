#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1000001][3];
int N;

int solve(int n, int method)
{
    if(dp[n][method] != -1)
    {
        return dp[n][method];
    }

    if(n == 1)
    {
        return dp[n][method] = 1;
    }

    if(method == 0)
    {
        if(n % 3 == 0)
        {
            return dp[n][method] = 1 + min(min(solve(n / 3, 0), solve(n / 3, 1)), solve(n / 3, 2));
        }
        else
        {
            return dp[n][method] = 987654321;
        }
    }

    if(method == 1)
    {
        if(n % 2 == 0)
        {
            return dp[n][method] = 1 + min(min(solve(n / 2, 0), solve(n / 2, 1)), solve(n / 2, 2));
        }
        else
        {
            return dp[n][method] = 987654321;
        }
    }

    if(method == 2)
    {
        if(n - 1 != 0)
        {
            return dp[n][method] = 1 + min(min(solve(n - 1, 0), solve(n - 1, 1)), solve(n - 1, 2));
        }
        else
        {
            return dp[n][method] = 987654321;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    memset(dp, -1, sizeof(dp));
    cout << min(min(solve(N, 0), solve(N, 1)), solve(N, 2)) - 1 << endl;
    
    return 0;
}