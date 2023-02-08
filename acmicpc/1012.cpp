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
int randInt = rand() % 2;

int a, b, T, M, N, K, cnt;
int Map[51][51];
int visited[51][51]; 
queue<pair<int, int> > q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int y, int x)
{
	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < N && nx < M && ny >= 0 && nx >= 0)
		{
			if(Map[ny][nx] == 1 && visited[ny][nx] == 0) // Map이 0인 부분 발견하면 DFS X
			{
				visited[ny][nx] = 1;
				DFS(ny, nx);
			}
		}
	}
}

void BFS(int y, int x)
{
	visited[y][x] = 1;
	q.push(make_pair(y, x));
	while(!q.empty())
	{
		int nodey = q.front().first;
		int nodex = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int ny = nodey + dy[i];
			int nx = nodex + dx[i];

			if(ny < N && nx < M && ny >= 0 && nx >= 0)
			{
				if(Map[ny][nx] == 1 && visited[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> T;
	while(T--)
	{	
		cnt = 0;
		memset(Map, 0, sizeof(Map));
		memset(visited, 0, sizeof(visited));

		cin >> M >> N >> K;

		for(int i = 0; i < K; i++)
		{
			cin >> a >> b;
			Map[b][a] = 1;
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(Map[i][j] == 1 && visited[i][j] == 0) // 새로운 배추 섬 발견
				{
					visited[i][j] = 1;
					cnt++;
					if(randInt)
						DFS(i, j);
					else
						BFS(i, j);
				}
			}
		}
		cout << cnt << endl;
	}

    return 0;
}