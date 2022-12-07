#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int x, y;
int M[101][101];
int S = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(M, 0, sizeof(M));

    cin >> N;

    while(N--)
    {
        cin >> x >> y;
        for(int i = x; i < x + 10; i++)
            for(int j = y; j < y + 10; j++)
                M[i][j]++;
    }

    for(int i = 1; i < 101; i++)
        for(int j = 1; j < 101; j++)
        {
            if(M[i][j] != 0)
                S++;
        }

    cout << S << endl;
    return 0;
}