#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int C, H, W;

const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool set(vector<vector<int> >& board, int y, int x, int type, int delta)
{
    bool ok = true;
    for(int i= 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size())
            ok = false;
        else if((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}

// board 의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
// board[i][j] = 0 아직 덮이지 않은 칸
int cover(vector<vector<int> >& board)
{
    // 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
    int y = -1, x = -1;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(board[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1)
            break;
    }
    
    // 기저 사례: 모든 칸을 채웠으면 1을 반환한다
    if(y == -1)
        return 1;
    
    int ret = 0;
    for(int type = 0; type < 4; type++)
    {
        if(set(board, y, x, type, 1))
            ret += cover(board);
        set(board, y, x, type, -1);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> C;
    
    while(C--)
    {
        cin >> H >> W;
        vector<vector<int> > board(H, vector<int>(W, 0));
        for(int i = 0; i < board.size(); i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < board[0].size(); j++)
            {
                if(s[j] == '#')
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
        cout << cover(board) << endl;
    }
    
    return 0;
}