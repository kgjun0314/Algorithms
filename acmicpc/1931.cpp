#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, a, b;
vector<pair<int, int> > v;
vector<pair<int, int> > v2;
int cnt = 1;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        v2.push_back(make_pair(v[i].second, v[i].first));
    }

    for(int i = 1; i < N; i++)
    {
        if(v2[i].second == v2[i - 1].second && v2[i].first < v2[i - 1].first)
        {
            int temp = v2[i - 1].first;
            v2[i - 1].first = v2[i].first;
            v2[i].first = temp;
        }
    }

    int end = v2[0].second;

    for(int i = 1; i < N; i++)
    {
        if(v2[i].first >= end)
        {
            cnt++;
            end = v2[i].second;
        }
    }

    cout << cnt << endl;

    return 0;
}