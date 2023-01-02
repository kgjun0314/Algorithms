#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, num;
int dp[1001][4];
int arr[1001][4];

int minfunc(int a, int b, int c)
{
    if(a <= b && a <= c)
    {
        return a;
    }
    else if(b <= a && b <= c)
    {
        return b;
    }
    else if(c <= a && c <= b)
    {
        return c;
    }
}

int main(void) 
{    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < 3; j++)
                dp[i][j] = arr[i][j];
        }
        else
        {
            dp[i][0] = arr[i][0] + (dp[i - 1][1] <= dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]);
            dp[i][1] = arr[i][1] + (dp[i - 1][0] <= dp[i - 1][2] ? dp[i - 1][0] : dp[i - 1][2]);
            dp[i][2] = arr[i][2] + (dp[i - 1][0] <= dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1]);
        }
    }

    cout << minfunc(dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]) << endl;

    return 0;
}