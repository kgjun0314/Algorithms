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

vector<vector<pair<int, int> > > graph(20001);
vector<long long> dist(20001, INF);
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
int N, M, X;
int u, v, w;
int Max = -1;

void dijkstra(int source)
{
    dist[source] = 0;
    pq.push(make_pair(dist[source], source));
    
    while(!pq.empty())
    {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(d > dist[curr])
        {
            continue;
        }

        for(auto next : graph[curr])
        {
            if(dist[next.first] > dist[curr] + next.second)
            {
                dist[next.first] = dist[curr] + next.second;
                pq.push(make_pair(dist[next.first], next.first));
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    for(int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    for(int i = 1; i <= N; i++)
    {
        dijkstra(i);
        int go = dist[X];
        fill(dist.begin(), dist.end(), INF);

        dijkstra(X);
        int back = dist[i];
        if(Max < go + back)
            Max = go + back;
            
        fill(dist.begin(), dist.end(), INF);
    }

    cout << Max << endl;

    return 0;
}