#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

long long N, K;
vector<long long> weight(101);
vector<long long> value(101);
vector<vector<long long> > dp(101, vector<long long>(100001));

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> K;

	for(long long i = 0; i < N; i++)
	{
		cin >> weight[i] >> value[i];
	}

	for(long long i = 0; i < N; i++)
	{
		for(long long w = 0; w <= K; w++)
		{
			if(w - weight[i] >= 0)
			{
				dp[i + 1][w] = max(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
			}
			dp[i + 1][w] = max(dp[i + 1][w], dp[i][w]);
		}
	}

	cout << dp[N][K] << endl;
    return 0;
}