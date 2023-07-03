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
#include <cstdlib>
#include <set>
#include <cmath>
#define endl "\n"
using namespace std;

long long n, x;

long long is_prime(long long n)
{
    if(n == 0 || n == 1)
        return 0;
    for(long long d = 2; d <= sqrt(n); d++)
    {
        if(n % d == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> x;
        while(true)
        {
            if(is_prime(x))
            {
                cout << x << endl;
                break;
            }
            x++;
        }
    }
    
    return 0;
}