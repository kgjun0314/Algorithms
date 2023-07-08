#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#include <cstdlib>
#define endl "\n"
using namespace std;

int N, M, K;
int minval = 4000001;
string row;
int board[2001][2001];
int s_wboard[2001][2001];
int s_bboard[2001][2001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(board, 0, sizeof(board));
	memset(s_wboard, 0, sizeof(s_wboard));
	memset(s_bboard, 0, sizeof(s_bboard));
	

	cin >> N >> M >> K;


	for(int i = 1; i <= N; i++)
	{
		cin >> row;
		for(int j = 0; j < M; j++)
		{
			if(row[j] == 'B')
				board[i][j + 1] = 0;
			else if(row[j] == 'W')
				board[i][j + 1] = 1;
		}
	}

	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if((i + j) % 2 == 0 && board[i][j] == 0)
				s_wboard[i][j] = 1;
			if((i + j) % 2 == 1 && board[i][j] == 1)
				s_wboard[i][j] = 1;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if((i + j) % 2 == 0 && board[i][j] == 1)
				s_bboard[i][j] = 1;
			if((i + j) % 2 == 1 && board[i][j] == 0)
				s_bboard[i][j] = 1;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			
			s_wboard[i][j] = s_wboard[i][j - 1] + s_wboard[i][j];
			s_bboard[i][j] = s_bboard[i][j - 1] + s_bboard[i][j];
		}
	}

	for(int j = 1; j <= M; j++)
	{
		for(int i = 1; i <= N; i++)
		{
			s_wboard[i][j] = s_wboard[i - 1][j] + s_wboard[i][j];
			s_bboard[i][j] = s_bboard[i - 1][j] + s_bboard[i][j];
		}
	}

	for(int i = N; i >= K; i--)
	{
		for(int j = M; j >= K; j--)
		{
			minval = min(minval, min(s_bboard[i][j] - s_bboard[i - K][j] - s_bboard[i][j - K] + s_bboard[i - K][j - K], s_wboard[i][j] - s_wboard[i - K][j] - s_wboard[i][j - K] + s_wboard[i - K][j - K]));
		}
	}

	cout << minval << endl;

    return 0;
}