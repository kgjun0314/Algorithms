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

const int MAX = 987654321;

int N, M;
int Map[1001][1001];
int Distance[1001][1001][2];
string input;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<pair<int, int>, int> > q;

bool IsValid(int y, int x)
{
	return (y >= 0 && y < N && x >= 0 && x < M);
}

int bfs(int y, int x)
{
	q.push(make_pair(make_pair(y, x), Map[y][x]));
	Distance[y][x][Map[y][x]] = 1;
	while(!q.empty())
	{
		int currenty = q.front().first.first;
		int currentx = q.front().first.second;
		int currentbroken = q.front().second;
		q.pop();

		if(currenty == N - 1 && currentx == M - 1)
		{
			return Distance[currenty][currentx][currentbroken];
		}

		for(int i = 0; i < 4; i++)
		{
			int ny = currenty + dy[i];
			int nx = currentx + dx[i];

			// 다음 위치가 벽이고 부순 적이 없으면 한번 부수고 currentbroken을 1로 바꿔준다. 다음 위치가 벽일 때 currentbroken이 0이라면 당연히 방문하지 않은 위치이다. 벽을 한번이라도 부쉈다면 currentbroken이 1이기 때문이다.
			if(IsValid(ny, nx) && Map[ny][nx] == 1 && currentbroken == 0)
			{
				q.push(make_pair(make_pair(ny, nx), Map[ny][nx]));
				Distance[ny][nx][Map[ny][nx]] = Distance[currenty][currentx][currentbroken] + 1;
			}
			
			// 다음 위치가 벽이 아니고 방문하지 않은 곳일 때, currentbroken은 유지시키며 이동한다.
			if(IsValid(ny, nx) && Map[ny][nx] == 0 && Distance[ny][nx][currentbroken] == 0)
			{
				q.push(make_pair(make_pair(ny, nx), currentbroken));
				Distance[ny][nx][currentbroken] = Distance[currenty][currentx][currentbroken] + 1;
			}
		}
	}

	return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(Map, 0, sizeof(Map));
	memset(Distance, 0, sizeof(Distance));

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> input;
		for(int j = 0; j < M; j++)
		{
			if(input[j] == '1')
			{
				Map[i][j] = 1;
			}
		}
	}

	cout << bfs(0, 0) << endl;

    return 0;
}
