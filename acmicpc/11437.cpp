#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define endl "\n";
using namespace std;

int N, M, A, B;
int parent[50001];
int depth[50001];
int visited[50001];
vector<int> graph[50001];

void DFS(int x, int d)
{
    visited[x] = 1;
    depth[x] = d;
    for(auto y : graph[x])
    {
        if(!visited[y])
        {
            parent[y] = x;
            DFS(y, d + 1);
        }
    }
}

int LCA(int a, int b)
{
    while(depth[a] != depth[b])
    {
        if(depth[a] > depth[b])
            a = parent[a];
        else
            b = parent[b];
    }

    while(a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
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

    cin >> M;
    while(M--)
    {
        cin >> A >> B;
        cout << LCA(A, B) << endl;
    }

    return 0;
}