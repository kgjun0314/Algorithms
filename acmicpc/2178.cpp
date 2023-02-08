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

int M, N;
string s;
int Map[101][101];
int visited[101][101]; 
int dist[101][101];
queue<pair<int, int> > q;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

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

			if(ny < N && nx < M && ny >= 0 && nx >= 0)
			{
				if(Map[ny][nx] == 1 && visited[ny][nx] == 0 && dist[ny][nx] > dist[nodey][nodex] + 1)
				{
					visited[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					dist[ny][nx] = dist[nodey][nodex] + 1;
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

	memset(Map, 0, sizeof(Map));
	memset(visited, 0, sizeof(visited));

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			dist[i][j] = 10001;
		}
	}

	for(int i = 0; i < N; i++)
	{
		cin >> s;
		for(int j = 0; j < s.length(); j++)
		{
			Map[i][j] = s[j] - '0';
		}
	}
	
	dist[0][0] = 1;
	visited[0][0] = 1;
	BFS(0, 0);
	cout << dist[N - 1][M - 1] << endl;

    return 0;
}