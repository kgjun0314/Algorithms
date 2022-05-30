#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int M[64][64];

void solve(int x, int y, int N)
{
    int start = M[y][x];
    bool flag = true;
    
    for(int i = y; i < y + N; i++)
    {
        for(int j = x; j < x + N; j++)
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
        if(start == 0)
        {
            cout << "0";
        }
        else if(start == 1)
        {
            cout << "1";
        }
    }
    
    else
    {
        int size = N / 2;
    
        cout << "(";
        solve(x, y, size);
        solve(x + size, y, size);
        solve(x, y + size, size);
        solve(x + size, y + size, size);
        cout << ")";
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
        string s;
        cin >> s;
        for(int j = 0; j < N; j++)
        {
            M[i][j] = s[j] - '0';
        }
    }
    
    solve(0, 0, N);
    cout << endl;
    
    return 0;
}