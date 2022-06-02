#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long N, B;
long long M[5][5];
long long temp[5][5];
long long ans[5][5];

void MatrixMultipl(long long X[5][5], long long Y[5][5])
{   
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                temp[i][j] += X[i][k] * Y[k][j];
            }
            temp[i][j] %= 1000;
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
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
    
    cin >> N >> B;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> M[i][j];
        }
        ans[i][i] = 1;
    }
    
    while(B > 0)
    {
        if(B % 2 == 1)
            MatrixMultipl(ans, M); // ans = ans * M
        MatrixMultipl(M, M); // M = M * M
        B /= 2;
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }
    
    return 0;
}