#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string M[65];
int b = 0, w = 0;

void solve(int x, int y, int n)
{
    int start = M[x][y];
    bool flag = true;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(M[x + i][y + j] != start)
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
        if(start == '1')
        {
            cout << string("1");
        }
        else if(start == '0')
        {
            cout << string("0");
        }
    }
    
    else
    {
        int size = n / 2;

        cout << "(";

        solve(x, y,  n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);

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
    string row;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> row;
        M[i] = row;
    }
    
    solve(0, 0, N);
    cout << endl;
    
    return 0;
}