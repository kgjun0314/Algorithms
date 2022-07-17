#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int fib[41];

int fibo(int n)
{
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i < 41; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}
    
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    cout << fibo(n) << ' ' << n - 2;
    
    return 0;
}