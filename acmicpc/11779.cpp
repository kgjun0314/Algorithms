#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#include <cmath>
#include <climits>
#define endl "\n"
using namespace std;

int n, m, a, b, w, s, e;
vector<vector<pair<int, int> > > graph;
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
vector<long long> dist;
vector<int> prevnode;

void dijkstra(int s)
{
    dist[s] = 0;
    prevnode[s] = s;

    pq.push(make_pair(dist[s], s));

    while(!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if(cur_dist > dist[cur_node])
            continue;
        for(auto next : graph[cur_node])
        {
            if(dist[next.second] > cur_dist + next.first)
            {
                dist[next.second] = cur_dist + next.first;
                prevnode[next.second] = cur_node;
                pq.push(make_pair(dist[next.second], next.second));
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    dist.resize(n + 1, INT_MAX);
    prevnode.resize(n + 1);
    graph.assign(n + 1, vector<pair<int, int> >());

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(w, b));
    }

    cin >> s >> e;

    dijkstra(s);

    cout << dist[e] << endl;

    vector<int> route;

    int cur = e;
    while(cur != s)
    {
        route.push_back(cur);
        cur = prevnode[cur];
    }
    route.push_back(s);

    cout << route.size() << endl;

    for(int i = route.size() - 1; i > -1; i--)
    {
        cout << route[i] << " ";
    }

    cout << endl;

	return 0;
}