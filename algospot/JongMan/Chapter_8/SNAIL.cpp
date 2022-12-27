#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
double dp[1001][1001];

double climb(int days, int climbed)
{
	if(days == m)
	{
		return climbed >= n ? 1 : 0;
	}
	if(dp[days][climbed] != -1)
	{
		return dp[days][climbed];
	}
	return dp[days][climbed] = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2);
}

int main(void)
{
	int C;
	cin >> C;
	while(C--)
	{
		cin >> n >> m;
		for(int i = 0; i < 1001; i++) 
		{
			for(int j = 0; j < 1001; j++) 
			{
				dp[i][j] = -1;
			}
		}
		cout.precision(10);
		cout << climb(0, 0) << endl;
	}
	return 0;
}