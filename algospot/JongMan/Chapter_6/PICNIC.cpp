#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int C, n, m;
bool areFriends[10][10];

int countPairings(bool taken[10])
{
    int firstFree = -1;
    
    for(int i = 0; i < n; i++)
    {
        if(!taken[i])
        {
            firstFree = i;
            break;
        }
    }
    
    if(firstFree == -1)
        return 1;
    
    int ret = 0;
    
    for(int pairWith = (firstFree+1); pairWith < n; pairWith++)
    {
        if(!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = true;
            taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = false;
            taken[pairWith] = false;
        }
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
        cin >> n >> m;
        memset(areFriends, 0, sizeof(areFriends));
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }
        bool taken[10];
        memset(taken, 0, sizeof(taken));
        cout << countPairings(taken) << endl;
    }
    
    return 0;
}