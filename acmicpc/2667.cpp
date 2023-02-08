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
int randInt = rand() % 2;

int N, cnt, res = 0;
string s;
vector<int> Map[26];
vector<vector<int> > visited(26, vector<int>(26, 0));
vector<int> Count;
queue<pair<int, int> > q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void DFS(int y, int x)
{
	for(int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

        if(ny < N && nx < N && ny >= 0 && nx >= 0)
        {
            if(Map[ny][nx] == 1 && visited[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                cnt++;
                DFS(ny, nx);
            }
        }
	}
}

void BFS(int y, int x)
{
	visited[y][x] = 1;
	q.push(make_pair(y, x));
	while(!q.empty())
	{
		int nodey = q.front().first;
		int nodex = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int ny = nodey + dy[i];
			int nx = nodex + dx[i];

			if(ny < N && nx < N && ny >= 0 && nx >= 0)
			{
				if(Map[ny][nx] == 1 && visited[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					cnt++;
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

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> s;
		for(int j = 0; j < N; j++)
		{
			Map[i].push_back(s[j] - '0');
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(Map[i][j] == 1 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				cnt = 1;
				if(randInt)
					DFS(i, j);
				else
					BFS(i, j);
				Count.push_back(cnt);
				res++;
			}
		}
	}

	sort(Count.begin(), Count.end());
	cout << res << endl;

	for(int i = 0; i < Count.size(); i++)
	{
		cout << Count[i] << endl;
	}

    return 0;
}