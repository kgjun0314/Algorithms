#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, x, y;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    vector<pair<int, int> > v;
    vector<int> rank;
    
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
        rank.push_back(1);
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(j != i)
            {
                if(v[j].first > v[i].first && v[j].second > v[i].second)
                {
                    rank[i]++;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        cout << rank[i] << ' ';
    }
    
    return 0;
}