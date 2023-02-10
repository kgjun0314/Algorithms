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

int M, N, t, result = 0;
int Map[1001][1001];
queue<pair<int, int> > q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool IsInside(int y, int x)
{
	return (y >= 0 && y < N && x >= 0 && x < M);
}

void bfs()
{
	while(!q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int ny = cury + dy[i];
			int nx = curx + dx[i];

			if(IsInside(ny, nx) && Map[ny][nx] == 0)
			{
				Map[ny][nx] = Map[cury][curx] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> M >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> t;
			Map[i][j] = t;
			if(Map[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(Map[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
			if(result < Map[i][j])
			{
				result = Map[i][j];
			}
		}
	}

	cout << result - 1 << endl;

    return 0;
}