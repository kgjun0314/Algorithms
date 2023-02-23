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
#include <cstdlib>
#define endl "\n"
using namespace std;

const long long INF = 1LL << 60;
int V, E, K;
int u, v, w;
vector<vector<pair<int, int> > > graph(20001);
vector<long long> dist(20001, INF);
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > que;

template <typename T> bool chmin(T& a, T b)
{
	if(a > b)
	{
		a = b;
		return true;
	}
	else
	{
		return false;
	}
}

void dijkstra()
{
	dist[K] = 0;
	que.push(make_pair(dist[K], K));

	while(!que.empty())
	{
		int v = que.top().second;
		long long d = que.top().first;
		que.pop();

		if(d > dist[v])
		{
			continue;
		}
		
		for(int next = 0; next < graph[v].size(); next++)
		{
			if(chmin(dist[graph[v][next].first], dist[v] + graph[v][next].second))
			{
				que.push(make_pair(dist[graph[v][next].first], graph[v][next].first));
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> V >> E;
	cin >> K;
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dijkstra();

	for(int v = 1; v <= V; v++)
	{
		if(dist[v] < INF)
		{
			cout << dist[v] << endl;
		}
		else
		{
			cout << "INF" << endl;
		}
	}

    return 0;
}
