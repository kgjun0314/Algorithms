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

vector<long long> v;
vector<long long> dist;
int N, cnt = 0;
long long x;

long long gcd(long long a, long long b)
{
    if(b)
        return gcd(b, a % b);
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while(N--)
    {
        cin >> x;
        v.push_back(x);
    }

    for(int i = 1; i < v.size(); i++)
    {
        dist.push_back(v[i] - v[i - 1]);
    }

    long long gcdval = dist[0];

    for(int i = 1; i < dist.size(); i++)
        gcdval = gcd(gcdval, dist[i]);

    for(int i = 0; i < dist.size(); i++)
    {
        cnt += dist[i] / gcdval - 1;
    }

    cout << cnt << endl;

    return 0;
}