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

int N;
int a, b;
int minx = 10001, miny = 10001, maxx = -10001, maxy = -10001;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while(N--)
    {
        cin >> a >> b;
        if(a <= minx)
        {
            minx = a;
        }
        if(a >= maxx)
        {
            maxx = a;
        }
        if(b <= miny)
        {
            miny = b;
        }
        if(b >= maxy)
        {
            maxy = b;
        }
    }

    cout << (maxy - miny) * (maxx - minx) << endl;

    return 0;
}