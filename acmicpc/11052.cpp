#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N;
vector<int> dp;
vector<int> cards;

int dpfunc(int n)
{
    int ret = 0;
    for(int i = n, j = 1; i > 0; i--, j++)
    {
        if(dp[i] + dp[j] > ret)
            ret = dp[i] + dp[j];
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    dp.resize(N + 1);
    cards.resize(N + 1);
    for(int i = 1; i <= N; i++)
    {
        cin >> cards[i];
    }

    dp[1]= cards[1];

    for(int i = 2; i <= N; i++)
    {
        dp[i] = max(cards[i], dpfunc(i - 1));
    }

    cout << dp[N] << endl;

    return 0;
}