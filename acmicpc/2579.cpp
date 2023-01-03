#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, maxval, num;
vector<int> a;
int dp[3][301];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    a.push_back(0);
    for(int i = 1; i <= N; i++)
    {
        cin >> num;
        a.push_back(num);
    }
    dp[2][1] = a[1];
    dp[1][2] = a[1] + a[2];
    dp[2][2] = a[2];
    for(int i = 3; i <= N; i++)
    {
        dp[1][i] = dp[2][i - 1] + a[i];
        dp[2][i] = max(dp[1][i - 2], dp[2][i - 2]) + a[i];
    }
    cout << max(dp[1][N], dp[2][N]) << endl;
    return 0;
}