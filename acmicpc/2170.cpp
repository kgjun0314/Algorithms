#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

const int MAX = 1000000001;
const int MIN = -MAX;
int Start = MIN;
int End = MIN;
int N, x, y, S = 0;
vector<pair<int, int> > v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        if(Start == MIN && End == MIN)
        {
            Start = v[i].first;
            End = v[i].second;
        }

        else if(v[i].first >= Start && v[i].first <= End)
        {
            if(v[i].second >= End)
            {
                End = v[i].second;
            }
        }

        else if(v[i].first > Start)
        {
            S += (End - Start);
            Start = v[i].first;
            End = v[i].second;
        }
    }

    S += (End - Start);

    cout << S << endl;

    return 0;
}