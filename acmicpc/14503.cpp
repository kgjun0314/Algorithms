#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

struct Point {
	int r;
	int c;
	int d;
};

int N, M;
int r, c, d;
int cnt = 0;
int room[51][51];
int isCleared[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isValid(int r, int c)
{
	return (0 <= r && r < N && 0 <= c && c < M && room[r][c] == 0);
}

void clear(int r, int c, int d)
{
	bool isAdjCleared = true;
	if(isCleared[r][c] == 0)
	{
		isCleared[r][c] = 1;
		cnt++;
	}

	for(int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(isValid(nr, nc) && isCleared[nr][nc] == 0)
		{
			isAdjCleared = false;
		}
	}

	if(isAdjCleared)
	{
		if(d == 0 || d == 1)
		{
			if(isValid(r + dr[d + 2], c + dc[d + 2]))
			{
				clear(r + dr[d + 2], c + dc[d + 2], d);
			}
			else
			{
				return;
			}
		}
		else if(d == 2 || d == 3)
		{
			if(isValid(r + dr[d - 2], c + dc[d - 2]))
			{
				clear(r + dr[d - 2], c + dc[d - 2], d);
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		d = d - 1;
		if(d == -1)
			d = 3;
		while(!isValid(r + dr[d], c + dc[d]) || isCleared[r + dr[d]][c + dc[d]] != 0)
		{
			d = d - 1;
			if(d == -1)
				d = 3;
		}
		clear(r + dr[d], c + dc[d], d);
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(isCleared, 0, sizeof(isCleared));

	cin >> N >> M;

	cin >> r >> c >> d;

	Point cur;
	cur.r = r;
	cur.c = c;
	cur.d = d;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> room[i][j];
		}
	}

	clear(cur.r, cur.c, cur.d);

	cout << cnt << endl;

    return 0;
}