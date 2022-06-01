#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int M[64][64];

void solve(int y, int x, int N)
{
    int start = M[y][x];
    bool flag = true;
    
    for(int j = y; j < y + N; j++)
    {
        for(int i = x; i < x + N; i++)
        {
            if(M[j][i] != start)
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
        solve(y, x, size);
        solve(y, x + size, size);
        solve(y + size, x, size);
        solve(y + size, x + size, size);
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
    
    for(int j = 0; j < N; j++)
    {
        string s;
        cin >> s;
        for(int i = 0; i < N; i++)
        {
            M[j][i] = s[i] - '0';
        }
    }
    
    solve(0, 0, N);
    cout << endl;
    
    return 0;
}