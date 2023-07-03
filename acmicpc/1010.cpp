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
#include <cmath>
#define endl "\n"
using namespace std;

int T, N, M;
long long dp[31][31];

long long C(int n, int r)
{
    if(dp[n][r] != 0)
        return dp[n][r];
    else if(r == 0 || r == n)
        return dp[n][r] = 1;
    else
        return dp[n][r] = C(n - 1, r - 1) + C(n - 1,  r);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0, sizeof(dp));

    cin >> T;

    while(T--)
    {
        cin >> N >> M;
        cout << C(M, N) << endl;
    }

    return 0;
}