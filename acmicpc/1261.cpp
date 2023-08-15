#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <queue>
#define endl "\n"
#define INF 987654321
using namespace std;

int N, M;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string line;
int map[101][101];
int visited[101][101];
int cnt[101][101];

bool isValid(int r, int c)
{
    return (1 <= r && r <= N && 1 <= c && c <= M && !visited[r][c]);
}

void DFS(int r, int c, int prevcnt)
{
    if(cnt[r][c] <= prevcnt)
        return;
    else
        cnt[r][c] = prevcnt;
    
    if(r == N && c == M)
        return;
    
    for(int i = 0; i < 4; i++)
    {
        if(isValid(r + dr[i], c + dc[i]))
        {
            visited[r + dr[i]][c + dc[i]] = true;
            DFS(r + dr[i], c + dc[i], prevcnt + (map[r + dr[i]][c + dc[i]] ? 1 : 0));
            visited[r + dr[i]][c + dc[i]] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= N; i++)
    {
        cin >> line;
        for(int j = 0; j < line.length(); j++)
        {
            map[i][j + 1] = line[j] - '0';
            cnt[i][j + 1] = INF;
        }
    }

    visited[1][1] = true;
    DFS(1, 1, 0);
    
    cout << cnt[N][M] << endl;

    return 0;
}