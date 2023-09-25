#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define endl "\n";
using namespace std;

int T, N, K, X, Y, W;
int D[1001];
vector<int> graph[1001];
int indegree[1001];
int dp[1001];
vector<int> sorted;
queue<int> q;

void topologicalSort()
{
    for(int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    for(int i = 1; i <= N; i++)
    {
        int popped = q.front();
        dp[popped] = dp[popped] + D[popped];
        q.pop();
        for(int j : graph[popped])
        {
            indegree[j]--;
            dp[j] = max(dp[j], dp[popped]);
            if(indegree[j] == 0)
            {
                q.push(j);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--)
    {
        for(int i = 0; i <= 1000; i++)
        {
            graph[i].clear();
        }
        memset(D, 0, sizeof(D));
        memset(indegree, 0, sizeof(indegree));
        memset(dp, 0, sizeof(dp));

        cin >> N >> K;
        for(int i = 1; i <= N; i++)
        {
            cin >> D[i];
        }
        for(int i = 1; i <= K; i++)
        {
            cin >> X >> Y;
            graph[X].push_back(Y);
            indegree[Y]++;
        }
        cin >> W;

        topologicalSort();

        cout << dp[W] << endl;
    }

    return 0;
}
