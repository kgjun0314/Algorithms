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
#include <cmath>
#include <climits>
#include <set>
#define endl "\n"
using namespace std;

int N;
int ypos, xpos;
vector<vector<int> > graph;
vector<vector<int> > dist;
vector<vector<bool> > visited;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int shark = 2;
int eat = 0;
int ans = 0;
queue<pair<int, int> > q;

bool isValid(int y, int x)
{
    return (1 <= y && y <= N && 1 <= x && x <= N && !visited[y][x]);
}

pair<int, int> BFS(int y, int x)
{
    q.push(make_pair(y, x));
    visited[y][x] = true;
    dist[y][x] = 0;
    graph[y][x] = 0;

    while(!q.empty())
    {
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if(!isValid(ny, nx) || graph[ny][nx] > shark)
                continue;
            visited[ny][nx] = true;
            dist[ny][nx] = dist[cury][curx] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    bool fail = true;
    int min_dist = INT_MAX;
    pair<int, int> target;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(graph[i][j] != 0 && !(i == y && j == x) && graph[i][j] < shark)
            {
                if(dist[i][j] < min_dist)
                {
                    fail = false;
                    min_dist = dist[i][j];
                    target = make_pair(i, j);
                }
            }
        }
    }

    if(fail)
        return make_pair(-1, -1);
    else
        return target;
}


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    graph.resize(N + 1, vector<int>(N + 1));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 9)
            {
                ypos = i;
                xpos = j;
            }
        }
    }

    while(true)
    {
        dist.assign(N + 1, vector<int>(N + 1, INT_MAX));
        visited.assign(N + 1, vector<bool>(N + 1, false));
        pair<int, int> fish = BFS(ypos, xpos);
        if(fish.second == -1)
            break;
        ans += dist[fish.first][fish.second];
        graph[ypos][xpos] = 0;
        graph[fish.first][fish.second] = 9;
        eat++;
        if(eat == shark)
        {
            shark++;
            eat = 0;
        }
        ypos = fish.first;
        xpos = fish.second;
    }

    cout << ans << endl;

	return 0;
}