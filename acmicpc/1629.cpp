#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(long long A, long long B, long long C)
{
    long long result = 1;
    long long x = A % C;
    while(B > 0)
    {
        if(B % 2 == 1)
            result = (result * x) % C;
        x = (x * x) % C;
        B = B / 2;
    }
    return result % C;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long A, B, C;
    
    cin >> A >> B >> C;
    
    cout << solve(A, B, C) << endl;
    
    return 0;
}