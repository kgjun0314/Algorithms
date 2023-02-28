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

vector<vector<pair<int, int> > > graph(100001);
int visited[100001];
int N;
int maxdia = 0;
int maxnode;
int v, t, w;

void DFS(int source, int length)
{
	visited[source] = 1;

	if(length > maxdia)
	{
		maxdia = length;
		maxnode = source;
	}

	for(int next = 0; next < graph[source].size(); next++)
	{
		if(!visited[graph[source][next].first])
		{
			DFS(graph[source][next].first, length + graph[source][next].second);
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> v;
		while(true)
		{
			cin >> t;
			if(t == -1)
			{
				break;
			}
			cin >> w;
			graph[v].push_back(make_pair(t, w));
		}
	}

	memset(visited, 0, sizeof(visited));
	maxdia = 0;
	DFS(1, 0);

	memset(visited, 0, sizeof(visited));
	maxdia = 0;
	DFS(maxnode, 0);

	cout << maxdia << endl;

    return 0;
}
