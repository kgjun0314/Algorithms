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
#include <set>
#define endl "\n"
using namespace std;

int T, K, cost;
int dp[501][501];
vector<int> files;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    
    while(T--)
    {
        cin >> K;
        files.resize(K + 1);
        for(int i = 1; i <= K; i++)
        {
            cin >> cost;
            files[i] = files[i - 1] + cost;
        }
        
        for(int i = 0; i <= 500; i++)
        {
            for(int j = 0; j <= 500; j++)
            {
                dp[i][j] = INT_MAX;
            }
        }

        for(int sz = 1; sz <= K; sz++)
        {
            for(int st = 1; st + sz - 1 <= K; st++)
            {
                int ed = st + sz - 1;
                if(sz == 1)
                    dp[st][ed] = 0;
                else
                {
                    int mc = files[ed] - files[st - 1];
                    for(int mi = st; mi < ed; mi++)
                    {
                        dp[st][ed] = min(dp[st][ed], dp[st][mi] + dp[mi + 1][ed] + mc);
                    }
                }
            }
        }

        cout << dp[1][K] << endl;
    }

	return 0;
}