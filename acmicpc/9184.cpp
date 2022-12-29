#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

long long a, b, c;
long long dp[21][21][21];

long long w(long long a, long long b, long long c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {   
        return 1;
    }

    if(a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }

    if(dp[a][b][c] != -1)
    {
        return dp[a][b][c];
    }

    if(a < b && b < c)
    {
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return dp[a][b][c];
    }

    else
    {
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return dp[a][b][c];
    }
}

int main(void) 
{    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    while(true)
    {
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1)
        {
            break;
        }
        memset(dp, -1, sizeof(dp));

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl; 
    }

    return 0;
}