#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
#define endl "\n";
using namespace std;

long long N, M, A, B, C, cmd;
long long parent[18][100001][2];
long long depth[100001];
long long visited[100001];
vector<pair<long long, long long> > graph[100001];

void DFS(long long x, long long d)
{
    visited[x] = 1;
    depth[x] = d;
    for(auto y : graph[x])
    {
        if(!visited[y.first])
        {
            parent[0][y.first][0] = x;
            parent[0][y.first][1] = y.second;
            DFS(y.first, d + 1);
        }
    }
}

long long LCA(long long a, long long b, long long cmd)
{
    long long S = 0;

    if (depth[a] < depth[b])
        swap(a, b);

    for(long long k = 17; k >= 0; k--)
    {
        if(depth[a] - depth[b] >= (1 << k))
        {   
            S += parent[k][a][1];
            a = parent[k][a][0];
        }
    }

    if(a == b)
    {
        if(cmd == 1)
        {
            cout << S << endl;
            return 0;
        }
        return a;
    }

    for (long long k = 17; k >= 0; k--)
    {
        if(parent[k][a][0] != parent[k][b][0])
        {
            S += parent[k][a][1];
            a = parent[k][a][0];

            S += parent[k][b][1];
            b = parent[k][b][0];
        }
    }

    S += parent[0][a][1] + parent[0][b][1];

    if(cmd == 1)
    {
        cout << S << endl;
        return 0;
    }
    return parent[0][a][0];
}

void LCA2(long long a, long long b, long long c, long long lca)
{
    long long dist_A = depth[a] - depth[lca];
    long long dist_B = depth[b] - depth[lca];

    if(dist_A + 1 >= c)
    {
        long long hight = c - 1;
        for(long long k = 17; k >= 0; k--)
        {
            if(hight >= (1 << k))
            {   
                a = parent[k][a][0];
                hight -= pow(2, k);
            }
        }
        cout << a << endl;
    }
    else
    {
        long long hight = dist_B - (c - dist_A) + 1;
        for(long long k = 17; k >= 0; k--)
        {
            if(hight >= (1 << k))
            {   
                b = parent[k][b][0];
                hight -= pow(2, k);
            }
        }
        cout << b << endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(parent, 0, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    memset(visited, 0, sizeof(visited));

    cin >> N;
    for(long long i = 0; i < N - 1; i++)
    {   
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        graph[B].push_back(make_pair(A, C));
    }   

    DFS(1, 0);

    for(long long k = 1; k <= 17; k++)
    {
        for(long long i = 1; i <= N; i++)
        {
            long long tmp = parent[k - 1][i][0];
            if(parent[k - 1][tmp][0] == 0)
                continue;
            parent[k][i][0] = parent[k - 1][tmp][0];
            parent[k][i][1] = parent[k - 1][tmp][1] + parent[k - 1][i][1];
        }
    }

    cin >> M;
    while(M--)
    {
        cin >> cmd;

        if(cmd == 1)
        {
            cin >> A >> B;
            LCA(A, B, cmd);
        }
        else
        {
            cin >> A >> B >> C;
            LCA2(A, B, C, LCA(A, B, cmd));
        }
    }

    return 0;
}