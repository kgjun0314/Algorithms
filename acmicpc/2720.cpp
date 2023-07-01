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

int T, C;
int cntQ = 0, cntD = 0, cntN = 0, cntP = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--)
    {
        cntQ = 0;
        cntD = 0;
        cntN = 0;
        cntP = 0;

        cin >> C;
        cntQ = C / 25;
        C = C % 25;
        cntD = C / 10;
        C = C % 10;
        cntN = C / 5;
        C = C % 5;
        cntP = C / 1;
        C = C % 1;

        cout << cntQ << " " << cntD << " " << cntN << " " << cntP << endl;
    }

    return 0;
}