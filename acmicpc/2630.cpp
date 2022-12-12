#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[129][129];

int solve_w(int N, int x, int y)
{
    if(N == 1 && board[x][y] == 0)
    {
        return 1;
    }

    else if(N == 1 && board[x][y] == 1)
    {
        return 0;
    }

    bool flag = true;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[x + i][y + j] == 1)
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
        return 1;
    }


    return solve_w(N / 2, x, y) + solve_w(N / 2, x, y + N / 2) + solve_w(N / 2, x + N / 2, y) + solve_w(N / 2, x + N / 2, y + N / 2);
}

int solve_b(int N, int x, int y)
{
    if(N == 1 && board[x][y] == 1)
    {
        return 1;
    }

    else if(N == 1 && board[x][y] == 0)
    {
        return 0;
    }

    bool flag = true;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[x + i][y + j] == 0)
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
        return 1;
    }



    return solve_b(N / 2, x, y) + solve_b(N / 2, x, y + N / 2) + solve_b(N / 2, x + N / 2, y) + solve_b(N / 2, x + N / 2, y + N / 2);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int W = solve_w(N, 0, 0);
    int B = solve_b(N, 0, 0);


    cout << W << endl << B << endl;

    return 0;
}