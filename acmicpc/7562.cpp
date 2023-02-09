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

int T, I, result;
int spy, spx;
int epy, epx;
queue<pair<pair<int, int>, int> > q;
int visited[301][301];

bool isValid(int y, int x)
{
	if(y >= 0 && y <= I - 1 && x >= 0 && x <= I - 1 && !visited[y][x])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void bfs(int sourcey, int sourcex)
{
	q.push(make_pair(make_pair(sourcey, sourcex), 0));
	visited[sourcey][sourcex] = 1;
	while(!q.empty())
	{
		int currenty = q.front().first.first;
		int currentx = q.front().first.second;
		int currentDepth = q.front().second;
		q.pop();
		if(currenty == epy && currentx == epx)
		{
			result = currentDepth;
			break;
		}
		for(int i = -2; i <= 2; i++)
		{
			for(int j = -2; j <= 2; j++)
			{
				if(!(i == -2 && j == -1) && !(i == -2 && j == 1) && !(i == -1 && j == -2) && !(i == -1 && j == 2) && !(i == 1 && j == -2) && !(i == 1 && j == 2) && !(i == 2 && j == -1) && !(i == 2 && j == 1))
				{
					continue;
				}
				else
				{
					if(isValid(currenty + i, currentx + j))
					{
						q.push(make_pair(make_pair(currenty + i, currentx + j), currentDepth + 1));
						visited[currenty + i][currentx + j] = 1;
					}
				}
			}
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> T;
	while(T--)
	{
		memset(visited, 0, sizeof(visited));
		while(!q.empty())
		{
			q.pop();
		}
		cin >> I;
		cin >> spy >> spx;
		cin >> epy >> epx;
		bfs(spy, spx);
		cout << result << endl;
	}

    return 0;
}