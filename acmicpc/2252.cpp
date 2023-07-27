#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define endl "\n";
using namespace std;

int N, M, A, B;
vector<int> graph[32001];
queue<int> q;
vector<int> sorted;
int indegree[32001];

void topologicalSort()
{
    for(int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    for(int i = 1; i <= N; i++)
    {
        int popnum = q.front();
        q.pop();
        sorted.push_back(popnum);
        for(int j = 0; j < graph[popnum].size(); j++)
        {
            if(--indegree[graph[popnum][j]] == 0)
                q.push(graph[popnum][j]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(indegree, 0, sizeof(indegree));

    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        graph[A].push_back(B);
        indegree[B]++;
    }

    topologicalSort();

    for(int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;

    return 0;
}
