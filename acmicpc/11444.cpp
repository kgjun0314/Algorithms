#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
long long M[2][2] = {{1, 1}, {1, 0}};
long long temp[2][2];
long long ans[2][2] = {{1, 0}, {0, 1}};

void MatrixMultipl(long long X[2][2], long long Y[2][2])
{   
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                temp[i][j] += X[i][k] * Y[k][j];
            }
            temp[i][j] %= 1000000007;
        }
    }
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            X[i][j] = temp[i][j];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    while(n > 0)
    {
        if(n % 2 == 1)
            MatrixMultipl(ans, M); // ans = ans * M
        MatrixMultipl(M, M); // M = M * M
        n /= 2;
    }
    
    cout << ans[0][1] << endl;
    
    return 0;
}