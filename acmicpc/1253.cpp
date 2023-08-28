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
#include <cmath>
#include <climits>
#include <set>
#define endl "\n"
using namespace std;

int N, L, R, cnt = 0;
vector<long long> v;
long long sum;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        long long target = v[i];
        L = 0;
        R = N - 1;
        while(L < R)
        {
            sum = v[L] + v[R];
            if(sum == target)
            {
                if(L != i && R != i)
                {
                    cnt++;
                    break;
                }
                else if(L == i)
                    L++;
                else if(R == i)
                    R--;
            }
            else
            {
                if(sum < target)
                    L++;
                else if(sum > target)
                    R--;
            }
        }
    }

    cout << cnt << endl;

	return 0;
}