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

int D = 4, L = 4, S = 1, N;
int dD, dL, dS;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        dD = D + L + S;
        dL = L * 2 + 4 * S;
        dS = S * 4;
        D = dD;
        L = dL;
        S = dS;
    }

    cout << D << endl;

    return 0;
}