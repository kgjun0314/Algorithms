#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string WB[8] = 
{
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = 
{
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

string Board[50];
int N, M, cnt = 0, temp, min_val = 98765432;
string row;

int WB_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(Board[x+i][y+j] != WB[i][j])
                cnt++;
        }
    }
    return cnt;
}

int BW_cnt(int x, int y)
{
    int cnt = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(Board[x+i][y+j] != BW[i][j])
                cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        cin >> row;
        Board[i] = row;
    }
    
    for(int i = 0; i + 8 <= N; i++)
    {
        for(int j = 0; j + 8 <= M; j++)
        {
            temp = min(WB_cnt(i, j), BW_cnt(i, j));
            if(temp < min_val)
            {
                min_val = temp;
            }
        }
    }
    
    cout << min_val;
    return 0;
}