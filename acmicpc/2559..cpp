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

int N, K;
int i, j;
int Max = -987654321;
int num;
int dp[100001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> K;

	dp[0] = 0;

	for(int t = 1; t <= N; t++)
	{
		cin >> num;
		dp[t] = dp[t - 1] + num;
	}

	for(int t = K; t <= N; t++)
	{
		Max = max(dp[t] - dp[t - K], Max);
	}

	cout << Max << endl;

    return 0;
}