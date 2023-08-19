#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int T, n;
vector<vector<int> > sticker;
vector<vector<int> > dp;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    while(T--)
    {
        cin >> n;
        sticker.assign(2, vector<int>(n + 1, 0));
        dp.assign(2, vector<int>(n + 1, 0));

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> sticker[i][j];
            }
        }

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        
        for(int j = 1; j < n; j++)
        {
            for(int i = 0; i < 2; i++)
            {
                if(j == 1)
                {
                    dp[i][j] = dp[(i + 1) % 2][j - 1] + sticker[i][j];
                }
                else
                {
                    dp[i][j] = max(max(dp[0][j - 2], dp[1][j - 2]), dp[(i + 1) % 2][j - 1]) + sticker[i][j];
                }
            }
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
    }

    return 0;
}