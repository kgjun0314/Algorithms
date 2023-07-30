#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
#define endl "\n";
using namespace std;

int N, M, A, B, C;
int parent[18][100001][3];
int depth[100001];
int visited[100001];
vector<pair<int, int> > graph[100001];

void DFS(int x, int d)
{
    visited[x] = 1;
    depth[x] = d;
    for(auto y : graph[x])
    {
        if(!visited[y.first])
        {
            parent[0][y.first][0] = x;
            parent[0][y.first][1] = y.second;
            parent[0][y.first][2] = y.second;
            DFS(y.first, d + 1);
        }
    }
}

void LCA(int a, int b)
{
    int minvalue = 1000001;
    int maxvalue = 0;

    if (depth[a] < depth[b])
        swap(a, b);

    for(int k = 17; k >= 0; k--)
    {
        if(depth[a] - depth[b] >= (1 << k))
        {   
            int tmpmin = parent[k][a][1];
            int tmpmax = parent[k][a][2];
            a = parent[k][a][0];
            minvalue = min(minvalue, tmpmin);
            maxvalue = max(maxvalue, tmpmax);
        }
    }

    if(a == b)
    {
        cout << minvalue << " " << maxvalue << endl;
        return;
    }

    for (int k = 17; k >= 0; k--)
    {
        if(parent[k][a][0] != parent[k][b][0])
        {
            int tmpmin = parent[k][a][1];
            int tmpmax = parent[k][a][2];
            a = parent[k][a][0];
            minvalue = min(minvalue, tmpmin);
            maxvalue = max(maxvalue, tmpmax);

            tmpmin = parent[k][b][1];
            tmpmax = parent[k][b][2];
            b = parent[k][b][0];
            minvalue = min(minvalue, tmpmin);
            maxvalue = max(maxvalue, tmpmax);
        }
    }

    minvalue = min(minvalue, min(parent[0][a][1], parent[0][b][1]));
    maxvalue = max(maxvalue, max(parent[0][a][2], parent[0][b][2]));

    cout << minvalue << " " << maxvalue << endl;
    return;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(parent, 0, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 18; i++)
        for(int j = 0; j < 100001; j++)
        {
            parent[i][j][1] = 1000001;
            parent[i][j][2] = 0;
        }

    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {   
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
        graph[B].push_back(make_pair(A, C));
    }   

    DFS(1, 0);

    for(int k = 1; k <= 17; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            int tmp = parent[k - 1][i][0];
            if(parent[k - 1][tmp][0] == 0)
                continue;
            parent[k][i][0] = parent[k - 1][tmp][0];
            parent[k][i][1] = min(parent[k - 1][i][1], parent[k - 1][tmp][1]);
            parent[k][i][2] = max(parent[k - 1][i][2], parent[k - 1][tmp][2]);
        }
    }

    cin >> M;
    while(M--)
    {
        cin >> A >> B;
        LCA(A, B);
    }

    return 0;
}