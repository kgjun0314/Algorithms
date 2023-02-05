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
#define endl "\n"
using namespace std;

vector<int> graph[100001];
vector<int> visited(100001, 0);
int cnt = 0;
int N, M, R;

void DFS(int cur)
{
	visited[cur] = ++cnt;

	for(auto next : graph[cur])
	{
		if(visited[next])
		{
			continue;
		}
		DFS(next);
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M >> R;

	for(int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1; i <= N; i++)
	{
		sort(graph[i].rbegin(), graph[i].rend());
	}

	DFS(R);

	for(int i = 1; i <= N; i++)
	{
		cout << visited[i] << endl;
	}

    return 0;
}