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
#include <set>
#define endl "\n"
using namespace std;

int N, M;
int i, j;
int num;
int dp[100001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	dp[0] = 0;

	for(int t = 1; t <= N; t++)
	{
		cin >> num;
		dp[t] = dp[t - 1] + num;
	}

	for(int t = 1; t <= M; t++)
	{
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << endl;
	}

    return 0;
}