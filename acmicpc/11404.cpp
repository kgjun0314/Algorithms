#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#include <cstdlib>
#define endl "\n"
using namespace std;

const long long INF = 1LL << 60;
int n, m;
long long a, b, c;
vector<vector<long long> > dp;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	cin >> m;

	vector<vector<long long> > dp(n + 1, vector<long long> (n + 1, INF));

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}

	for(int i = 1; i <= n; i++)
	{
		dp[i][i] = 0;
	}

	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(dp[i][j] == INF)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << dp[i][j] << " ";
			}
		}
		cout << endl;
	}
	
    return 0;
}