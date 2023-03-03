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

int n, m, a, b, cnt = 0;
bool isTree, treecnt = 0;
vector<int> graph[501];
int visited[501]; 

bool dfs(int cur, int parent)
{
	visited[cur] = 1;
	for(auto child : graph[cur])
	{
		if(child == parent)
		{
			continue;
		}
		if(visited[child])
		{
			return false;
		}
		if(dfs(child, cur) == false)
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	while(true)
	{
		cin >> n >> m;
		if(n == 0 && m == 0)
		{
			break;
		}

		int ans = 0;
		memset(visited, 0 ,sizeof(visited));
		for(int i = 1; i <= n; i++) graph[i].clear();

		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				if(dfs(i, 0))
				{
					ans++;
				}
			}
		}

		cout << "Case " << ++cnt << ": ";
		if(ans == 0)
		{
			cout << "No trees." << endl;
		}
		else if(ans == 1)
		{
			cout << "There is one tree." << endl;
		}
		else
		{
			cout << "A forest of " << ans << " trees." << endl;
		}
	}

    return 0;
}