#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, height, minRain = 101, maxRain = 0, maxval = 0, temp;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<vector<int> > map;
vector<vector<int> > invmap;
vector<vector<int> > visited;

bool isValid(int r, int c)
{
    return (1 <= r && r <= N && 1 <= c && c <= N && invmap[r][c] == 1 && !visited[r][c]);
}

void DFS(int r, int c)
{
    visited[r][c] = 1;
    for(int i = 0; i < 4; i++)
    {
        if(isValid(r + dy[i], c + dx[i]))
            DFS(r + dy[i], c + dx[i]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    map.resize(N + 1, vector<int>(N + 1));

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            if(maxRain < map[i][j])
                maxRain = map[i][j];
            if(minRain > map[i][j])
                minRain = map[i][j];
        }
    }

    for(int t = minRain - 1; t <= maxRain; t++)
    {
        invmap.assign(N + 1, vector<int>(N + 1, 1));
        visited.assign(N + 1, vector<int>(N + 1, 0));

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(map[i][j] <= t)
                    invmap[i][j] = 0;
            }
        }

        temp = 0;
        
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(isValid(i, j))
                {
                    temp++;
                    DFS(i, j);
                }
            }
        }

        if(temp > maxval)
            maxval = temp;
    }

    cout << maxval << endl;

    return 0;
}