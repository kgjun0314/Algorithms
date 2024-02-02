#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
#include <stack>
using namespace std;
void Init()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

void input();
void countIsland();
void dfs(int y, int x);
bool isValid(int y, int x);
void melt();

int N, M, cnt = 0, zerocnt, t = 0;
int Map[301][301];
int temp[301][301];
int visited[301][301];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1}; 

void input()
{
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
}

void countIsland()
{
	cnt = 0;
	memset(visited, 0, sizeof(visited));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(!visited[i][j] && Map[i][j] != 0)
			{
				cnt++;
				visited[i][j] = 1;
				dfs(i, j);
			}
		}
	}
}

void dfs(int y, int x)
{
	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(isValid(ny, nx))
		{
			if(!visited[ny][nx] && Map[ny][nx] != 0)
			{
				visited[ny][nx] = 1;
				dfs(ny, nx);
			}
		}
	}
}

bool isValid(int y, int x)
{
	return (0 <= y && y <= N - 1 && 0 <= x && x <= M - 1);
}

void melt()
{
	t++;
	memset(temp, 0, sizeof(temp));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(Map[i][j] != 0)
			{
				zerocnt = 0;
				for(int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(isValid(ny, nx))
					{
						if(Map[ny][nx] == 0)
							zerocnt++;
					}
				}
				temp[i][j] = Map[i][j] - zerocnt;
				if(temp[i][j] < 0)
					temp[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			Map[i][j] = temp[i][j];
		}
	}
}

int main()
{
    Init();
	input();

	countIsland();
	if(cnt >= 2)
	{
		cout << 0 << endl;
		return 0;
	}

	while(cnt < 2)
	{
		melt();
		countIsland();
		if(cnt == 0)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	cout << t << endl;

	return 0;
}