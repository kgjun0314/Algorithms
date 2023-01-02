#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, num;
int triangle[501][501];
int dp[501][501];

int path(int y, int x)
{
    if(y == N - 1)
    {
        return triangle[y][x];
    }

    else if(dp[y][x] != -1)
    {
        return dp[y][x];
    }
    return dp[y][x] = max(triangle[y][x] + path(y + 1, x), triangle[y][x] + path(y + 1, x + 1));
}

int main(void) 
{    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> num;
            triangle[i][j] = num;
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << path(0, 0) << endl;

    return 0;
}