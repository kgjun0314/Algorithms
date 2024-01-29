#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

int N, M, x, y, K;
int Map[20][20];
int directions[1000];
int dice[6] = {0, 0, 0, 0, 0, 0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
/*
	0번째 : 북쪽 방향
	1번째 : 서쪽 방향
	2번째 : 윗면
	3번째 : 동쪽 방향
	4번째 : 남쪽 방향
	5번째 : 바닥면
*/

bool isValid(int r, int c);
void input();
void roll();

bool isValid(int r, int c)
{
	return (0 <= r && r <= N - 1 && 0 <= c && c <= M - 1);
}

void input()
{
	cin >> N >> M >> x >> y >> K;
	for(int r = 0; r < N; r++)
	{
		for(int c = 0; c < M; c++)
		{
			cin >> Map[r][c];
		}
	}
	for(int i = 0; i < K; i++)
	{
		cin >> directions[i];
	}
}



void roll()
{
	int dir;
	for(int i = 0; i < K; i++)
	{
		if(directions[i] == 1)
		{
			int nx = x + dx[directions[i] - 1];
			int ny = y + dy[directions[i] - 1];
			if(!isValid(nx, ny))
				continue;
			else
			{
				x = nx;
				y = ny;
				int temp[6];
				temp[0] = dice[0];
				temp[1] = dice[5];
				temp[2] = dice[1];
				temp[3] = dice[2];
				temp[4] = dice[4];
				temp[5] = dice[3];
				for(int j = 0; j < 6; j++)
				{
					dice[j] = temp[j];
				}
				if(Map[x][y] == 0)
				{
					Map[x][y] = dice[5];
				}
				else
				{
					dice[5] = Map[x][y];
					Map[x][y] = 0;
				}
				cout << dice[2] << endl;
			}
		}
		else if(directions[i] == 2)
		{
			int nx = x + dx[directions[i] - 1];
			int ny = y + dy[directions[i] - 1];
			if(!isValid(nx, ny))
				continue;
			else
			{
				x = nx;
				y = ny;
				int temp[6];
				temp[0] = dice[0];
				temp[1] = dice[2];
				temp[2] = dice[3];
				temp[3] = dice[5];
				temp[4] = dice[4];
				temp[5] = dice[1];
				for(int j = 0; j < 6; j++)
				{
					dice[j] = temp[j];
				}
				if(Map[x][y] == 0)
				{
					Map[x][y] = dice[5];
				}
				else
				{
					dice[5] = Map[x][y];
					Map[x][y] = 0;
				}
				cout << dice[2] << endl;
			}
		}
		else if(directions[i] == 3)
		{
			int nx = x + dx[directions[i] - 1];
			int ny = y + dy[directions[i] - 1];
			if(!isValid(nx, ny))
				continue;
			else
			{
				x = nx;
				y = ny;
				int temp[6];
				temp[0] = dice[2];
				temp[1] = dice[1];
				temp[2] = dice[4];
				temp[3] = dice[3];
				temp[4] = dice[5];
				temp[5] = dice[0];
				for(int j = 0; j < 6; j++)
				{
					dice[j] = temp[j];
				}
				if(Map[x][y] == 0)
				{
					Map[x][y] = dice[5];
				}
				else
				{
					dice[5] = Map[x][y];
					Map[x][y] = 0;
				}
				cout << dice[2] << endl;
			}
		}
		else if(directions[i] == 4)
		{
			int nx = x + dx[directions[i] - 1];
			int ny = y + dy[directions[i] - 1];
			if(!isValid(nx, ny))
				continue;
			else
			{
				x = nx;
				y = ny;
				int temp[6];
				temp[0] = dice[5];
				temp[1] = dice[1];
				temp[2] = dice[0];
				temp[3] = dice[3];
				temp[4] = dice[2];
				temp[5] = dice[4];
				for(int j = 0; j < 6; j++)
				{
					dice[j] = temp[j];
				}
				if(Map[x][y] == 0)
				{
					Map[x][y] = dice[5];
				}
				else
				{
					dice[5] = Map[x][y];
					Map[x][y] = 0;
				}
				cout << dice[2] << endl;
			}
		}
	}
}

int main()
{
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	input();

	roll();

	return 0;
}