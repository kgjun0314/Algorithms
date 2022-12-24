#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

int C;
const int INF = 987654321;
string N;
int dp[10002];

int classify(int a, int b)
{
	string M = N.substr(a, b - a + 1);
	if(M == string(M.size(), M[0]))
	{
		return 1;
	}

	bool prograssive = true;
	for(int i = 0; i < M.size() - 1; i++)
	{
		if(M[i + 1] - M[i] != M[1] - M[0])
		{
			prograssive = false;
		}
	}
	if(prograssive && abs(M[1] - M[0]) == 1)
	{
		return 2;
	}

	bool alternating = true;
	for(int i = 0; i < M.size(); i++)
	{
		if(M[i] != M[i % 2])
		{
			alternating = false;
		}
	}

	if(alternating)
	{
		return 4;
	}

	if(prograssive)
	{
		return 5;
	}

	return 10;
}

int memorize(int begin)
{
	if(begin == N.size())
	{
		return 0;
	}
	if(dp[begin] != -1)
	{
		return dp[begin];
	}
	dp[begin] = INF;
	for(int L = 3; L <= 5; L++)
	{
		if(begin + L <= N.size())
		{
			dp[begin] = min(dp[begin], memorize(begin + L) + classify(begin, begin + L - 1));
		}
	}
	return dp[begin];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> C;
	while(C--)
	{
		cin >> N;
		memset(dp, -1, sizeof(dp));
		cout << memorize(0) << endl;
	}
	
	return 0;
}