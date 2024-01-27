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

int N, M, d, s;
int A[51][51];
int isCloud[51][51];
int disappeared[51][51];
int direction[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, -1, 1};

void input()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}
}

bool isValid_r(int r)
{
	return (1 <= r && r <= N);
}

bool isValid_c(int c)
{
	return (1 <= c && c <= N);
}

int _r(int r)
{
	if(isValid_r(r))
		return r;
	else
	{
		if(r < 1)
		{
			while(!isValid_r(r))
			{
				if(r < 1)
				{
					r = r + N;
				}
			}
		}
		else if(r > N)
		{
			while(!isValid_r(r))
			{
				if(r > N)
				{
					r = r - N;
				}
			}
		}
		return r;
	}
}

int _c(int c)
{
	if(isValid_c(c))
		return c;
	else
	{
		if(c < 1)
		{
			while(!isValid_c(c))
			{
				if(c < 1)
				{
					c = c + N;
				}
			}
		}
		else if(c > N)
		{
			while(!isValid_c(c))
			{
				if(c > N)
				{
					c = c - N;
				}
			}
		}
		return c;
	}
}

void addWater()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(isCloud[i][j] == 1)
				A[i][j]++;
		}
	}
}

void deleteCloud()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(isCloud[i][j] == 1)
			{
				isCloud[i][j] = 0;
				disappeared[i][j] = 1;
			}
		}
	}
}

void waterCopingBug()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(disappeared[i][j])
			{
				int count = 0;
				for(int d = 0; d < 4; d++)
				{
					int nr = i + dr[d];
					int nc = j + dc[d];
					if(isValid_r(nr) && isValid_c(nc))
					{
						if(A[nr][nc] != 0)
							count++;
					}
				}
				A[i][j] += count;
			}
		}
	}
}

void addCloud()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(A[i][j] >= 2 && !disappeared[i][j])
			{
				isCloud[i][j] = 1;
				A[i][j] -= 2;
			}
		}
	}
}

void moveCloud(int dir_r, int dir_c)
{	
	int temp[51][51];

	memset(temp, 0, sizeof(temp));

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(isCloud[i][j])
			{
				temp[_r(i + dir_r * s)][_c(j + dir_c * s)] = 1;
			}
		}
	}

	memset(isCloud, 0, sizeof(isCloud));

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			isCloud[i][j] = temp[i][j];
		}
	}
}

void rainDance()
{
	for(int i = 1; i <= M; i++)
	{
		memset(disappeared, 0, sizeof(disappeared));

		if(i == 1)
		{
			isCloud[N][1] = 1;
			isCloud[N][2] = 1;
			isCloud[N - 1][1] = 1;
			isCloud[N - 1][2] = 1;
		}

		cin >> d >> s;
		int dir_r = direction[d - 1][0];
		int dir_c = direction[d - 1][1];
		
		moveCloud(dir_r, dir_c);
		addWater();
		deleteCloud();
		waterCopingBug();
		addCloud();
	}
}

int countWater()
{
	int count = 0;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			count += A[i][j];
		}
	}

	return count;
}

int main(){
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	memset(isCloud, 0, sizeof(isCloud));
	memset(disappeared, 0, sizeof(disappeared));
	
	input();

	rainDance();

	cout << countWater() << endl;

	return 0;
}