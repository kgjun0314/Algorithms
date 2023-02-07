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

int N, E, V, a, b, dfscnt = 0, bfscnt = 0;

vector<int> graph[1001];
vector<int> visited(1001, 0);
queue<int> q;
vector<int> order;

void dfs(int cur)
{
	visited[cur] = 1;
	order.push_back(cur);
	for(int next = 0; next < graph[cur].size(); next++)
	{
		if(!visited[graph[cur][next]])
		{
			dfs(graph[cur][next]);
		}
	}
}

void bfs(int cur)
{
	q.push(cur);
	visited[cur] = 1;
	order.push_back(cur);
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		for(int next = 0; next < graph[current].size(); next++)
		{
			if(!visited[graph[current][next]])
			{
				q.push(graph[current][next]);
				visited[graph[current][next]] = 1;
				order.push_back(graph[current][next]);
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	cin >> E;
	cin >> V;

	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);

	for(int i = 0; i < order.size(); i++)
	{
		cout << order[i];
		cout << " ";
	}
	cout << endl;	

	for(int i = 0; i < visited.size(); i++)
	{
		visited[i] = 0;
	}
	order.clear();

	bfs(V);

	for(int i = 0; i < order.size(); i++)
	{
		cout << order[i];
		cout << " ";
	}
	cout << endl;

    return 0;
}