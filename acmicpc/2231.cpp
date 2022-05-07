#include <iostream>
using namespace std;

int N;

int solve(int N)
{
    for(int i = 1; i < N; i++)
    {
        int cnt = i;
        int temp = i;
        while(true)
        {
            cnt += (temp % 10);
            temp /= 10;
            if(temp == 0)
                break;
        }
        if(cnt == N)
            return i;
    }
    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    cout << solve(N) << endl;
    
    return 0;
}