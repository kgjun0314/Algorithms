#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#include <cmath>
#include <climits>
#define endl "\n"
using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    coins.resize(n);
    dp.resize(k + 1);
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    dp[0] = 1;

    for(int i = 0; i < coins.size(); i++) // 0, 1, 2
    {
        for(int j = coins[i]; j <= k; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << endl;

	return 0;
}