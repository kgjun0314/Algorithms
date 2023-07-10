#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, x, value = 2000000001;
int st, ed;
pair<int, int> answer;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    st = 0;
    ed = N - 1;

    while(true)
    {
        if(v[st] + v[ed] <= 0)
        {
            if(abs(v[st] + v[ed]) < abs(value))
            {
                value = v[st] + v[ed];
                answer.first = v[st];
                answer.second = v[ed];
            }
            st++;
        }

        else if(v[st] + v[ed] > 0)
        {
            if(abs(v[st] + v[ed]) < abs(value))
            {
                value = v[st] + v[ed];
                answer.first = v[st];
                answer.second = v[ed];
            }
            ed--;
        }
        
        if(st == ed)
        {
            cout << answer.first << " " << answer.second << endl;
            break;
        }
    }

    return 0;
}