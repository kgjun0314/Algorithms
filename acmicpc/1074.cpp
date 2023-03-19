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

int N, r, c, s, cnt = 0;

void solve(int y, int x, int s)
{
    if(y == r && x == c)
    {
        cout << cnt << endl;
        exit(0);
    }

    if(r < y + s && r >= y && c < x + s && c >= x)
    {
        solve(y, x, s / 2);
        solve(y, x + s / 2, s / 2);
        solve(y + s / 2, x, s / 2);
        solve(y + s / 2, x + s / 2, s / 2);
    }

    else
    {
        cnt += s * s;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;

    s = pow(2, N);

    solve(0, 0, s);
	
    return 0;
}