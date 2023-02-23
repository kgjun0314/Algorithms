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

const long long INF = 987654321;
int N, E;
int u, v, w;
int v1, v2;
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

vector<long long> dijkstra(int src)
{
	vector<long long> dist(20001, INF);
	dist[src] = 0;
	que.push(make_pair(dist[src], src));

	while(!que.empty())
	{
		int node = que.top().second;
		long long dis = que.top().first;
		que.pop();
		
		if(dis > dist[node])
		{
			continue;
		}

		for(int next = 0; next < graph[node].size(); next++)
		{
			if(chmin(dist[graph[node][next].first], dist[node] + graph[node][next].second))
			{
				que.push(make_pair(dist[graph[node][next].first], graph[node][next].first));
			}
		}
	}

	return dist;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> E;
	for(int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	cin >> v1 >> v2;

	vector<long long> from1 = dijkstra(1);
	vector<long long> fromv1 = dijkstra(v1);
	vector<long long> fromv2 = dijkstra(v2);

	long long result = min(from1[v1] + fromv1[v2] + fromv2[N], from1[v2] + fromv2[v1] + fromv1[N]);

	if(result >= INF)
	{
		cout << "-1" << endl;
	}
	else 
	{
		cout << result << endl;
	}

    return 0;
}