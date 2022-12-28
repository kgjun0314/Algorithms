#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int C, N;
int board[5][5];
int dp[5][5][10];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool isRange(int x, int y) 
{
    return (0 <= x && x < 5) && (0 <= y && y < 5);
}

int solve(const string & s, int x, int y, int index) 
{
    if(index >= s.length()) 
	{
        return 1;
    }

    if(!isRange(x, y) || board[x][y] != s[index]) 
	{
        return 0;
    }

    if(dp[x][y][index] != -1) 
	{
        return dp[x][y][index];
    }

    dp[x][y][index] = 0;

    for(int i = 0; i < 8; i++) 
	{
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nextIndex = index + 1;

        if(solve(s, nx, ny, nextIndex))
		{
            dp[x][y][index] = 1;
            return dp[x][y][index];
        }
    }

    return dp[x][y][index];
}

bool solution(const string & s) 
{
    for(int i = 0; i < 5; i++) 
	{
        for(int j = 0; j < 5; j++) 
		{
            if(solve(s, i, j, 0)) 
			{
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> C;

    while(C--)
	{

		for(int i = 0; i < 5; i++) 
		{
            for(int j = 0; j < 5; j++) 
			{
                char c;
                cin >> c;
                board[i][j] = c;
            }
        }

        cin >> N;

        for(int i = 0; i < N; i++) 
		{
            memset(dp, -1, sizeof(dp));
            string s;
            cin >> s;
            bool res = solution(s);
            cout << s << " " << ((res) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}