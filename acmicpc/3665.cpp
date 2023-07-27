#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define endl "\n";
using namespace std;

int t, n, ti, m, ai, bi;
int graph[501][501];
queue<int> q;
vector<int> sorted;
vector<int> oldRanking;
int indegree[501];

void topologicalSort()
{
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    for(int i = 1; i <= n; i++)
    {
        if(q.empty())
            break;

        int popnum = q.front();
        q.pop();
        sorted.push_back(popnum);
        for(int j = 1; j <= n; j++)
        {
            if(graph[popnum][j] == 1)
                if(--indegree[j] == 0)
                    q.push(j);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        while(!q.empty())
            q.pop();
        sorted.clear();
        oldRanking.clear();
        memset(indegree, 0, sizeof(indegree));
        memset(graph, 0, sizeof(graph));

        cin >> n;

        for(int j = 0; j < n; j++)
        {
            cin >> ti;
            oldRanking.push_back(ti);
        }

        for(int j = 0; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                graph[oldRanking[j]][oldRanking[k]] = 1;
                indegree[oldRanking[k]]++;
            }
        }

        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> ai >> bi;
            if(graph[ai][bi] == 1)
            {
                graph[ai][bi] = 0;
                indegree[bi]--;
                graph[bi][ai] = 1;
                indegree[ai]++;
            }
            else
            {
                graph[bi][ai] = 0;
                indegree[ai]--;
                graph[ai][bi] = 1;
                indegree[bi]++;
            }
        }

        topologicalSort();

        if(sorted.size() == n)
        {
            for(int i = 0; i < n; i++)
            {
                cout << sorted[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}