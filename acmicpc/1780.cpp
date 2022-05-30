#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a = 0, b = 0, c = 0;
int M[2200][2200];

void solve(int x, int y, int N)
{
    int start = M[x][y];
    bool flag = true;
    
    for(int i = x; i < x + N; i++)
    {
        for(int j = y; j < y + N; j++)
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
        if(start == -1)
        {
            a++;
        }
        else if(start == 0)
        {
            b++;
        }
        else if(start == 1)
        {
            c++;
        }
    }
    
    else
    {
        int size = N / 3;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                solve(x + size * i, y + size * j, size);
            }
        }
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
    
    cout << a << endl << b << endl << c << endl;
    
    return 0;
}