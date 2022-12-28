#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

double dp[51][101];
int C, N, D, P, T, Q;
int num;
int deg[51];
int path[51][51];
int v[51];

double search(int here, int days)
{
	if(days == D)
	{
		return (here == Q ? 1.0 : 0.0);
	}

	if(dp[here][days] > -0.5)
	{
		return dp[here][days];
	}

	dp[here][days] = 0;
	for(int there = 0; there < N; there++)
	{
		if(path[here][there])
		{
			dp[here][days] += search(there, days + 1) / deg[here];
		}
	}
	return dp[here][days];
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C;

	while(C--)
	{
		cin >> N >> D >> P;
		memset(path, 0, sizeof(path));

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				cin >> path[i][j];
			}
		}

		memset(deg, 0, sizeof(deg));

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(path[i][j] == 1)
				{
					deg[i]++;
				}
			}
		}

		cin >> T;
		
		for(int i = 0; i < T; i++)
		{
			cin >> v[i];
		}

		for(int i = 0; i < T; i++)
		{
			Q = v[i];
			for(int j = 0; j < 51; j++)
			{
				for(int k = 0; k < 101; k++)
				{
					dp[j][k] = -1;
				}			
			}
			cout.precision(8);
			cout << search(P, 0) << " ";
		}
		cout << endl;
	}

	return 0;
}