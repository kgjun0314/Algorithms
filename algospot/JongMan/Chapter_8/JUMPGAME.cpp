#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int C;
int n, board[100][100];
int cache[100][100];

int jump(int y, int x)
{
    if(y >= n || x >= n)
        return 0;
    if(y == n - 1 && x == n - 1)
        return 1;
    
    int& ret = cache[y][x];
    if(ret != -1)
        return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C;
    while(C--)
    {
        memset(board, 0, sizeof(board));
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> board[i][j];
            }
        }
        if(jump(0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}