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

int K, V, E, u, v;
vector<int> graph[20001];
int color[20001];

bool dfs(int current, int c)
{
	color[current] = c;
	for(int next = 0; next < graph[current].size(); next++)
	{
		if(color[graph[current][next]] == c)
		{
			return false;
		}
		if(color[graph[current][next]] == 0 && !dfs(graph[current][next], -c))
		{
			return false;
		}
	}

	return true;
}

void solve()
{
	for(int i = 0; i < V; i++)
	{
		if(color[i] == 0)
		{
			if(!dfs(i, 1))
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> K;

	while(K--)
	{
		for(int i = 0; i < 20001; i++)
		{
			graph[i].clear();
		}
		memset(color, 0, sizeof(color));

		cin >> V >> E;
		while(E--)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		solve();
	}

    return 0;
}
