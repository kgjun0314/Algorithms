#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int height;
int triangle[100][100];
int dp[100][100];

int path(int y, int x)
{
	if(y == height - 1)
		return triangle[y][x];
	
	if(dp[y][x] != -1)
		return dp[y][x];
	return dp[y][x] = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main(void)
{
	int C;
	cin >> C;
	while(C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> height;
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < i + 1; j++)
			{
				cin >> triangle[i][j];
			}
		}
		cout << path(0, 0) << endl;
	}
	return 0;
}
