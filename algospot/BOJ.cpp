#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
using namespace std;

int N, M;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string line;
vector<vector<int> > map;
vector<vector<bool> > visited;
vector<vector<int> > cnt;

bool isValid(int r, int c)
{
    return (1 <= r && r <= N && 1 <= c && c <= M);
}

void DFS(int r, int c, int prevcnt)
{
    if(!visited[r][c])
    {
        visited[r][c] = true;

        if(map[r][c] == 1)
            cnt[r][c] = prevcnt + 1;
        else
            cnt[r][c] = prevcnt;

        for(int i = 0; i < 4; i++)
        {
            if(isValid(r + dr[i], c + dc[i]))
            {
                DFS(r + dr[i], c + dc[i], cnt[r][c]);
            }
        }
    }
    else if(visited[r][c] && cnt[r][c] > prevcnt)
    {
        if(map[r][c] == 1)
            cnt[r][c] = prevcnt + 1;
        else
            cnt[r][c] = prevcnt;

        for(int i = 0; i < 4; i++)
        {
            if(isValid(r + dr[i], c + dc[i]))
            {
                DFS(r + dr[i], c + dc[i], cnt[r][c]);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;
    map.assign(N + 1, vector<int>(M + 1, 0));
    visited.assign(N + 1, vector<bool>(M + 1, false));
    cnt.assign(N + 1, vector<int>(M + 1, 0));

    for(int i = 1; i <= N; i++)
    {
        cin >> line;
        for(int j = 0; j < line.length(); j++)
        {
            map[i][j + 1] = line[j] - '0';
        }
    }

    DFS(1, 1, 0);
    
    cout << cnt[N][M] << endl;

    return 0;
}