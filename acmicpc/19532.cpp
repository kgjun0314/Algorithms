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

int a, b, c, d, e, f;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d >> e >> f;

    cout << (e * c - b * f) / (a * e - b * d) << " " << (a * f - d * c) / (a * e - b * d) << endl;

    return 0;
}