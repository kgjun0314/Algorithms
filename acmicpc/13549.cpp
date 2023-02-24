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

const int INF = 1LL >> 60;
int N, K, result;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int visited[100001];

bool isValid(int n)
{
	if(n >= 0 && n <= 100000 && !visited[n])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void dijkstra(int source)
{
	vector<int> dist(100001, INF);
	dist[source] = 0;

	pq.push(make_pair(dist[source], source));

	while(!pq.empty())
	{
		int currentNode = pq.top().second;
		int currentDist = pq.top().first;
		pq.pop();

		if(currentNode == K)
		{
			result = currentDist;
			break;
		}
		if(isValid(2 * currentNode))
		{
			pq.push(make_pair(currentDist, 2 * currentNode));
			visited[2 * currentNode] = 1;
		}		
		if(isValid(currentNode + 1))
		{
			pq.push(make_pair(currentDist + 1, currentNode + 1));
			visited[currentNode + 1] = 1;
		}
		if(isValid(currentNode - 1))
		{
			pq.push(make_pair(currentDist + 1, currentNode - 1));
			visited[currentNode - 1] = 1;
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(visited, 0, sizeof(visited));

	cin >> N >> K;

	dijkstra(N);

	cout << result << endl;

    return 0;
}