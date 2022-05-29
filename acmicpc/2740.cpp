#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    int A[101][101];
    int B[101][101];
    int C[101][101];
    memset(C, 0, sizeof(int));
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
        }
    }
    
    cin >> M >> K;
    
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            cin >> B[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= K; j++)
        {
            for(int k = 1; k <= M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int k = 1; k <= K; k++)
        {
            cout << C[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}