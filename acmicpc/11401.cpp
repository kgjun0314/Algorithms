#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
// #include <cmath>
using namespace std;

long long N, K, ans, mod = 1000000007;

long long pow(long long A, long long B)
{
    long long result = 1;
    long long x = A % mod;
    while(B > 0)
    {
        if(B % 2 == 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        B = B / 2;
    }
    return result % mod;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    
    long long A = 1, B = 1, C;
    
    for(long long i = 1; i <= N; i++)
    {
        A *= i;
        A %= mod;
    }
    
    for(long long i = 1; i <= K; i++)
    {
        B *= i;
        B %= mod;
    }
    
    for(long long i = 1; i <= N - K; i++)
    {
        B *= i;
        B %= mod;
    }
    
    C = pow(B, mod - 2);
    ans = (A * C) % mod;
    
    cout << ans << endl;
    return 0;
}