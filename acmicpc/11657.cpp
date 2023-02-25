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

const long long INF = 987654321;
int N, M;
int A, B, C;
bool exist_negative = false;
vector<long long> dist(501, INF);
vector<vector<pair<int, int> > > graph(501);

template<typename T> bool chmin(T& a, T b)
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

void bellmanford(int source)
{
	dist[source] = 0;

	for(int iter = 1; iter <= N; iter++)
	{
		bool update = false;
		for(int v = 1; v <= N; v++)
		{
			if(dist[v] == INF)
			{
				continue;
			}

			for(int next = 0; next < graph[v].size(); next++)
			{
				if(chmin(dist[graph[v][next].first], dist[v] + graph[v][next].second))
				{
					update = true;
				}
			}
		}

		if(!update)
		{
			break;
		}

		if(iter == N && update)
		{
			exist_negative = true;
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		graph[A].push_back(make_pair(B, C));
	}

	bellmanford(1);

	if(exist_negative)
	{
		cout << -1 << endl;
	}
	else
	{
		for(int v = 2; v <= N; v++)
		{
			if(dist[v] == INF)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dist[v] << endl;
			}
		}
	}

    return 0;
}