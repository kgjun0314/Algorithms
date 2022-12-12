#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int M[129][129];
int b = 0, w = 0;

void solve(int x, int y, int n)
{
    int start = M[x][y];
    bool flag = true;
    
    for(int i = x; i < x + n; i++)
    {
        for(int j = y; j < y + n; j++)
        {
            if(M[i][j] != start)
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
    
    if(flag == true)
    {
        if(start == 1)
        {
            b++;
        }
        else if(start == 0)
        {
            w++;
        }
    }
    
    else
    {
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> M[i][j];
        }
    }
    
    solve(0, 0, N);
    
    cout << w << endl << b << endl;
    
    return 0;
}