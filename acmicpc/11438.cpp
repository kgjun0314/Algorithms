#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define endl "\n";
using namespace std;

int N, M, A, B;
int parent[18][100001];
int depth[100001];
int visited[100001];
vector<int> graph[100001];

void DFS(int x, int d)
{
    visited[x] = 1;
    depth[x] = d;
    for(auto y : graph[x])
    {
        if(!visited[y])
        {
            parent[0][y] = x;
            DFS(y, d + 1);
        }
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int k = 17; k >= 0; k--)
    {
        if (depth[a] - depth[b] >= (1 << k))
            a = parent[k][a];
    }

    if (a == b)
        return a;

    for (int k = 17; k >= 0; k--)
    {
        if (parent[k][a] != parent[k][b])
        {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    return parent[0][a];
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
    for(int i = 0; i < N - 1; i++)
    {   
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }   

    DFS(1, 0);

    for(int k = 1; k <= 17; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            int tmp = parent[k - 1][i];
            parent[k][i] = parent[k - 1][tmp];
        }
    }

    cin >> M;
    while(M--)
    {
        cin >> A >> B;
        cout << LCA(A, B) << endl;
    }

    return 0;
}