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

int N, K, result;
queue<pair<int, int> > q;
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

void bfs(int source)
{
	q.push(make_pair(N, 0));
	visited[N] = 1;
	while(!q.empty())
	{
		int currentData = q.front().first;
		int currentDepth = q.front().second;
		q.pop();

		if(currentData == K)
		{
			result = currentDepth;
			break;
		}
		if(isValid(currentData - 1))
		{
			q.push(make_pair(currentData - 1, currentDepth + 1));
			visited[currentData - 1] = 1;
		}
		if(isValid(currentData + 1))
		{
			q.push(make_pair(currentData + 1, currentDepth + 1));
			visited[currentData + 1] = 1;
		}
		if(isValid(2 * currentData))
		{
			q.push(make_pair(2 * currentData, currentDepth + 1));
			visited[2 * currentData] = 1;
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

	bfs(N);

	cout << result << endl;

    return 0;
}