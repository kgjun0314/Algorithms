#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int dp[1001][1001];
string A, B;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> A >> B;

	for(int i = 0; i < A.length(); i++)
	{
		for(int j = 0; j < B.length(); j++)
		{
			dp[i + 1][j + 1] = max(max(dp[i + 1][j], dp[i][j + 1]), dp[i][j] + (A[i] == B[j]));
		}
	}

	cout << dp[A.length()][B.length()] << endl;
    return 0;
}