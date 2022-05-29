#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int paper[129][129];
int b = 0, w = 0;

void solve(int x, int y, int n)
{
    int temp = 0;
    for(int i = x; i < x + n; i++)
    {
        for(int j = y; j < y + n; j++)
        {
            if(paper[i][j])
            {
                temp++;
            }
        }
    }
    
    if(!temp)
        w++;
    else if(temp == n * n)
        b++;
    else
    {
        // i
        solve(x, y, n / 2);
        // ii
        solve(x, y + n / 2, n / 2);
        // iii
        solve(x + n / 2, y, n / 2);
        // iv
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
    memset(paper, 0, sizeof(int));
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }
    
    solve(0, 0, N);
    
    cout << w << endl << b << endl;
    
    return 0;
}