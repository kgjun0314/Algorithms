#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N;
int dp[1000001];

int solve(int N)
{
    if(dp[N] != -1)
    {
        return dp[N];
    }

    dp[N] = (solve(N - 1) + solve(N - 2)) % 15746;
    return dp[N];
}

int main(void) 
{    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    cin >> N;
    cout << solve(N);

    return 0;
}