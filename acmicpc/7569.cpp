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

int M, N, H, t, result = 0;
int Map[101][101][101];

int dz[2] = {1, -1};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

queue<pair<int, pair<int, int> > > q;

bool IsInside(int z, int y, int x)
{
	return (z >= 0 && z < H && y >= 0 && y < N && x >= 0 && x < M);
}

void bfs()
{
	while(!q.empty())
	{
		int curz = q.front().first;
		int cury = q.front().second.first;
		int curx = q.front().second.second;
		q.pop();

		for(int i = 0; i < 2; i++)
		{
			int nz = curz+ dz[i];

			if(IsInside(nz, cury, curx) && Map[nz][cury][curx] == 0)
			{
				Map[nz][cury][curx] = Map[curz][cury][curx] + 1;
				q.push(make_pair(nz, make_pair(cury, curx)));
			}
		}

		for(int i = 0; i < 4; i++)
		{
			int ny = cury + dy[i];
			int nx = curx + dx[i];

			if(IsInside(curz, ny, nx) && Map[curz][ny][nx] == 0)
			{
				Map[curz][ny][nx] = Map[curz][cury][curx] + 1;
				q.push(make_pair(curz, make_pair(ny, nx)));
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> M >> N >> H;
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < M; k++)
			{
				cin >> t;
				Map[i][j][k] = t;
				if(Map[i][j][k] == 1)
				{
					q.push(make_pair(i, make_pair(j, k)));
				}
			}
		}
	}
	bfs();

	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < N; j++)
		{
			for(int k = 0; k < M; k++)
			{
				if(Map[i][j][k] == 0)
				{
					cout << -1 << endl;
					return 0;
				}
				if(result < Map[i][j][k])
				{
					result = Map[i][j][k];
				}
			}
		}
	}
	cout << result - 1 << endl;

    return 0;
}