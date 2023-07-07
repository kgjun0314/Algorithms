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

int N, M, num;
int x_1, y_1, x_2, y_2;
int board[1026][1026];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(board, 0, sizeof(board));

	cin >> N >> M;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(j == 1)
				cin >> board[i][j];
			else
			{
				cin >> num;
				board[i][j] = board[i][j - 1] + num;
			}
		}
	}

	for(int i = 0; i < M; i++)
	{
		int ans = 0;
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for(int k = x_1; k <= x_2; k++)
		{
			ans += board[k][y_2] - board[k][y_1 - 1];
		}
		cout << ans << endl;
	}

    return 0;
}