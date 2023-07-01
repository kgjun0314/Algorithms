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

long long tmp;
long long N;
long long R;
int B;
string ans = "";

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;

    while(N != 0)
    {
        tmp = N / B;
        R = N % B;
        if(R < 10)
            ans = char(R + 48) + ans;
        else if(R >= 10)
            ans = char(R + 55) + ans;
        N = tmp;
    }

    cout << ans << endl;

    return 0;
}