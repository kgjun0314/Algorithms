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

vector<int> tree[100001];
vector<int> query;
int dp[100001];
int isVisited[100001];
int N, R, Q;

int dfs(int n)
{
	if(dp[n] != 0)
		return dp[n];
	isVisited[n] = true;
	int cnt = 1;
	for(int i = 0; i < tree[n].size(); i++)
	{
		int next = tree[n][i];
		if(isVisited[next])
			continue;
		cnt += dfs(next);
	}
	dp[n] = cnt;
	return cnt;
}

void input()
{
	int U, V;
	cin >> N >> R >> Q;
	for(int i = 0; i < N - 1; i++)
	{
		cin >> U >> V;
		tree[U].push_back(V);
		tree[V].push_back(U);
	}
	for(int i = 0; i < Q; i++)
	{
		cin >> U;
		query.push_back(U);
	}
}

void output()
{
	for(int i = 0; i < query.size(); i++)
		cout << dp[query[i]] << endl;
}

int main()
{
    init();
	memset(dp, 0, sizeof(dp));
	memset(isVisited, 0, sizeof(isVisited));
	input();
	dp[R] = dfs(R);
	output();
	
	return 0;
}