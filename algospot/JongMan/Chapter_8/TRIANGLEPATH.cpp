#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int height;
int triangle[100][100];
int cache[100][100];

int path(int y, int x)
{
	if(y == height - 1)
		return triangle[y][x];
	
	int& result = cache[y][x];
	if(result != -1)
		return result;
	return result = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main(void)
{
	int C;
	cin >> C;
	while(C--)
	{
		memset(cache, -1, sizeof(cache));
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
