#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
#include <stack>
#define endl '\n'
using namespace std;
void init()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int T, n;
int dp[10001];
vector<int> query;

void input()
{
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		query.push_back(n);
	}
	
	for(int i = 0; i <= 10000; i++)
	{
		dp[i] = 1;
	}
	for(int i = 2; i <= 10000; i++)
	{
		dp[i] += dp[i - 2];
	}
	for(int i = 3; i <= 10000; i++)
	{
		dp[i] += dp[i - 3];
	}
}

void output()
{
	for(int i = 0; i < query.size(); i++)
	{
		n = query[i];
		cout << dp[n] << endl;
	}
}

int main()
{
    init();
	input();
	output();

	return 0;
}