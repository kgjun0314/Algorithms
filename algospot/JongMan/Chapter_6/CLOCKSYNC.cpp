#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int C, ret, INF = 9999;

const char linked[10][17] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "x...xxxx........",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx.x......xx",
  ".xxxxx..........",
  "...xxx...x...x.."};

bool areAligned(vector<int>& clocks) {
  for(int i = 0; i < 16; i++)
    if(clocks[i] != 12) 
        return false;
  return true;
}

void push(vector<int>& clocks, int swtch)
{
    for(int i = 0; i < 16; i++)
    {
        if(linked[swtch][i] == 'x')
        {
            clocks[i] += 3;
            if(clocks[i] == 15) 
                clocks[i] = 3;
        }
    }
}

int solve(vector<int>& clocks, int swtch)
{
    if(swtch == 10) 
        return areAligned(clocks) ? 0 : INF;
    
    int ret = INF;
    for(int cnt = 0; cnt < 4; cnt++)
    {
        ret = min(ret, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
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
        vector<int> clocks(16, 0);
        for(int i = 0; i < 16; i++)
        {
            cin >> clocks[i];
        }
        
        ret = solve(clocks, 0);
        cout << (ret == INF ? -1 : ret) << endl;
    }
    
    return 0;
}