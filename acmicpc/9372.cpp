#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int T, N, M, a, b, cnt = 0;
vector<int> visited;
vector<vector<int> > graph;

void DFS(int node)
{
    visited[node] = 1;
    
    for(int i = 1; i <= N; i++)
    {
        if(graph[node][i] == 1 && !visited[i])
        {
            DFS(i);
            cnt++;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        cin >> N >> M;

        cnt = 0;
        visited.clear();
        graph.clear();
        visited.assign(N + 1, 0);
        for(int i = 0; i < N + 1; i++)
        {
            graph.push_back(vector<int>(N + 1, 0));
        }
        
        for(int i = 0; i < M; i++)
        {
            cin >> a >> b;

            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        DFS(1);
        cout << cnt << endl;
    }
    
    return 0;
}
