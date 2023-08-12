#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

long long N, M;
long long Left, Right, mid;
long long sum;
long long temp;
vector<long long> a;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    a.resize(N);

    Left = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        Right += a[i];
        Left = max(Left, a[i]);
    }

    while(Left <= Right)
    {
        sum = 0;
        temp = 1;
        mid = (Left + Right) / 2; // 블루레이의 크기

        for(int i = 0; i < N; i++)
        {
            if(sum + a[i] > mid)
            {
                sum = 0;
                temp++;
            }
            sum += a[i];
        }
        
        if(temp <= M)
            Right = mid - 1;
        else
            Left = mid + 1;
    }
    
    cout << Left << endl;

    return 0;
}