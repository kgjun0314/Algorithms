#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define endl "\n";
using namespace std;

int m, Q, n, x;
int f[20][200001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> f[0][i];
    }
    for(int k = 1; k <= 19; k++)
    {
        for(int i = 1; i <= m; i++)
        {
            int tmp = f[k - 1][i];
            f[k][i] = f[k - 1][tmp];
        }
    }

    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> n >> x;

        int cur = x;
        for(int j = 19; j >= 0; j--)
        {
            if(n & (1 << j))
                cur = f[j][cur];
        }
        cout << cur << endl;
    }

    return 0;
}