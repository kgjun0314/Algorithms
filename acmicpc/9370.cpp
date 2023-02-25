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
#include <cstdlib>
#define endl "\n"
using namespace std;

const int INF = 987654321;
int T;			// T: 테스트 케이스
int n, m, t;	// n: 노드의 개수, m: 간선의 개수, t: 목적 후보 노드의 개수
int s, g, h;	// s: 시작 노드, g: 반드시 지나야 하는 노드1, h: 반드시 지나야 하는 노드2
int a, b, d;	// a: 노드, b: 노드, d: 노드 a, b사이의 가중치
int x;			// x: 목적 노드
vector<vector<pair<int, int> > > graph(2001);
vector<pair<int, bool> > nominated;
int visited[2001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
vector<int> visitable;
vector<int> froms;
vector<int> fromg;
vector<int> fromh;

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

vector<int> dijkstra(int source)
{
	vector<int> dist(2001, INF);
	dist[source] = 0;
	pq.push(make_pair(dist[source], source));

	while(!pq.empty())
	{
		int curNode = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if(curDist > dist[curNode])
		{
			continue;
		}

		for(int next = 0; next < graph[curNode].size(); next++)
		{
			if(chmin(dist[graph[curNode][next].first], dist[curNode] + graph[curNode][next].second))
			{
				pq.push(make_pair(dist[graph[curNode][next].first], graph[curNode][next].first));
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

	cin >> T;
	while(T--)
	{
		for(int i = 0; i < graph.size(); i++)
		{
			while(!graph[i].empty())
			{
				graph[i].pop_back();
			}
		}
		nominated.clear();
		memset(visited, 0, sizeof(visited));
		visitable.clear();
		froms.clear();
		fromg.clear();
		fromh.clear();
	
		while(!pq.empty())
		{
			pq.pop();
		}

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b >> d;
			graph[a].push_back(make_pair(b, d));
			graph[b].push_back(make_pair(a, d));
		}
		for(int i = 0; i < t; i++)
		{
			cin >> x;
			nominated.push_back(make_pair(x, true));
		}

		vector<int> froms = dijkstra(s);
		vector<int> fromg = dijkstra(g);
		vector<int> fromh = dijkstra(h);

		for(int i = 0; i < t; i++)
		{
			if(froms[g] + fromg[h] + fromh[nominated[i].first] == froms[nominated[i].first] || froms[h] + fromh[g] + fromg[nominated[i].first] == froms[nominated[i].first])
			{
				continue;
			}
			else
			{
				nominated[i].second = false;
			}
		}
		
		for(int i = 0; i < t; i++)
		{
			if(nominated[i].second)
			{
				visitable.push_back(nominated[i].first);
			}
		}

		sort(visitable.begin(), visitable.end());

		for(int i = 0; i < visitable.size(); i++)
		{
			cout << visitable[i] << " ";
		}
		cout << endl;
	}

    return 0;
}