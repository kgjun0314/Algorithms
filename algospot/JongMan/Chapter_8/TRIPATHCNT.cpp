#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int height;
int triangle[100][100];
int dp[100][100];
int cdp[100][100];

int path(int y, int x)
{
	if(y == height - 1)
		return triangle[y][x];
	
	if(dp[y][x] != -1)
		return dp[y][x];
	return dp[y][x] = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x)
{
	if(y == height - 1)
	{
		return 1;
	}

	if(cdp[y][x] != -1)
	{
		return cdp[y][x];
	}
	cdp[y][x] = 0;
	if(path(y + 1, x + 1) >= path(y + 1, x))
	{
		cdp[y][x] += count(y + 1, x + 1);
	}
	if(path(y + 1, x + 1) <= path(y + 1, x))
	{
		cdp[y][x] += count(y + 1, x);
	}
	return cdp[y][x];
}

int main(void)
{
	int C;
	cin >> C;
	while(C--)
	{
		memset(dp, -1, sizeof(dp));
		memset(cdp, -1, sizeof(cdp));
		cin >> height;
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < i + 1; j++)
			{
				cin >> triangle[i][j];
			}
		}
		cout << count(0, 0) << endl;
	}
	return 0;
}