#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

const long long MAX = 1000000001;
const long long MIN = -MAX;
long long Start = MIN;
long long End = MIN;
long long N, M, x, y, S = 0;
vector<pair<long long, long long> > v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(long long i = 0; i < N; i++)
    {
        cin >> x >> y;

        if(x > y)
            v.push_back(make_pair(y, x));
    }
    sort(v.begin(), v.end());

    for(long long i = 0; i < N; i++)
    {
        if(Start == MIN && End == MIN)
        {
            Start = v[i].first;
            End = v[i].second;
        }

        else if(Start <= v[i].first && v[i].first <= End)
        {
            if(End <= v[i].second)
            {
                End = v[i].second;
            }
        }

        else if(Start < v[i].first)
        {
            S += (End - Start);
            Start = v[i].first;
            End = v[i].second;
        }
    }

    S += (End - Start);

    cout << M + 2 * S << endl;

    return 0;
}