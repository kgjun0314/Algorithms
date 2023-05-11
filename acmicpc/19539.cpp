#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, a, S, cnt = 0, cnt2 = 0;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        S += v[i];
    }
    
    if(S % 3 != 0)
    {
        cout << "NO" << endl;
        exit(0);
    }

    for(int i = 0; i < N; i++)
    {
        cnt += v[i] / 2;
    }

    if(cnt >= S / 3)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }

    return 0;
}