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

int N, E, a, b, cnt = 0;

vector<int> graph[101];
vector<int> visited(101, 0);
queue<int> q;
int randint = rand() % 2;

void dfs(int cur)
{
	visited[cur] = 1;
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

	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	if(randint)
		dfs(1);
	else
		bfs(1);

	for(int i = 2; i <= N; i++)
	{
		if(visited[i])
		{
			cnt++;
		}
	}

	cout << cnt << endl;

    return 0;
}