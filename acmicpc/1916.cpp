#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

const long long INF = 1LL << 60;

int N, M, A, B, W, S, E;
vector<vector<pair<long long, int> > > graph;
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > heap;
vector<long long> dist;

void Dijkstra(int s)
{
    dist[s] = 0;
    heap.push(make_pair(dist[s], s));
    
    while(!heap.empty())
    {
        int d = heap.top().first;
        int cur = heap.top().second;
        heap.pop();
        
        if(d > dist[cur])
            continue;

        for(auto next : graph[cur]) 
        {
            if(dist[next.first] > dist[cur] + next.second)
            {
                dist[next.first] = dist[cur] + next.second;
                heap.push(make_pair(dist[next.first], next.first));
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    graph.resize(N + 1);
    dist.assign(N + 1, INF);

    for(int i = 0; i < M; i++)
    {
        cin >> A >> B >> W;
        graph[A].push_back(make_pair(B, W));
    }
    cin >> S >> E;

    Dijkstra(S);

    cout << dist[E] << endl;
}