#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, M, safearea, tmp, maxval = -1;
int map[9][9];
int visited[9][9];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<pair<int, int> > emptyplace;
vector<pair<int, int> > virus;

bool isIn(int y, int x)
{
    return (1 <= y && y <= N && 1 <= x && x <= M);
}

void BFS(int y, int x)
{
    if(!visited[y][x] && map[y][x] == 0 && isIn(y, x))
    {
        visited[y][x] = 1;
        tmp--;

        for(int d = 0; d < 4; d++)
        {
            BFS(y + dy[d], x + dx[d]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(map, 0, sizeof(map));

    cin >> N >> M;

    safearea = N * M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 0)
                emptyplace.push_back(make_pair(i, j));
            else if(map[i][j] == 1)
                safearea--;
            else if(map[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
                safearea--;
            }
        }
    }
    
    for(int i = 0; i < emptyplace.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < j; k++)
            {
                memset(visited, 0, sizeof(visited));
                tmp = safearea - 3;
                map[emptyplace[i].first][emptyplace[i].second] = 1;
                map[emptyplace[j].first][emptyplace[j].second] = 1;
                map[emptyplace[k].first][emptyplace[k].second] = 1;
                for(int v = 0; v < virus.size(); v++)
                {
                    visited[virus[v].first][virus[v].second] = 1;
                    for(int i = 0; i < 4; i++)
                    {
                        BFS(virus[v].first + dy[i], virus[v].second + dx[i]);
                    }
                }
                maxval = max(maxval, tmp);
                map[emptyplace[i].first][emptyplace[i].second] = 0;
                map[emptyplace[j].first][emptyplace[j].second] = 0;
                map[emptyplace[k].first][emptyplace[k].second] = 0;
            }
        }
    }

    cout << maxval << endl;
    return 0;
}