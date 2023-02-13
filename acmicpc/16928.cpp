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
#include <cmath>
#define endl "\n"
using namespace std;

int N, M;
int graph[101];
int visited[101];
queue<pair<int, int> > q;

void bfs(int y, int x)
{
	q.push(make_pair(y, x));
	while(!q.empty())
	{
		int current = q.front().first;
		int count = q.front().second;
		q.pop();

		for(int i = 1; i <= 6; i++)
		{
			int next = current + i;
			if(next == 100)
			{
				cout << count + 1;
				return;
			}
			else if(next < 100)
			{
				while(graph[next] != 0)
				{
					next = graph[next];
				}
				if(!visited[next])
				{
					q.push(make_pair(next, count + 1));
					visited[next] = 1;
				}
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(graph, 0, sizeof(graph));
	memset(visited, 0, sizeof(visited));

	cin >> N >> M;

	while(N--)
	{
		int x, y;
		cin >> x >> y;
		graph[x] = y;
	}

	while(M--)
	{
		int u, v;
		cin >> u >> v;
		graph[u] = v;
	}
	
	bfs(1, 0);

    return 0;
}