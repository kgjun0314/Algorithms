#include <iostream>
#include <string>
using namespace std;

int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
char Board[5][5];
bool flag = false;

bool InRange(int x, int y)
{
    if(x < 0 || y < 0 || x >= 5 || y >= 5)
        return false;
    return true;
}

bool HasWord(int x, int y, const string& Word)
{
    if(!InRange(x, y))
        return false;
    
    if(Board[x][y] != Word[0])
        return false;
    
    if(Word.size() == 1)
        return true;
    
    for(int i = 0; i < 8; i++)
    {
        int Del_x = x + dx[i], Del_y = y + dy[i];
        if(HasWord(Del_x, Del_y, Word.substr(1)))
            return true;
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int C, N;
    string Word;
    
    cin >> C;
    
    for(int i = 0; i < C; i++)
    {
        for(int row = 0; row < 5; row++)
        {
            cin >> Board[row];
        }
        cin >> N;
    
        for(int i = 0; i < N; i++)
        {
            bool flag = false;
            cin >> Word;
            for(int x = 0; x < 5; x++)
                for(int y = 0; y < 5; y++)
                {
                    if(HasWord(x, y, Word))
                    {
                        flag = true;
                        break;
                    }
                }
            if(flag)
            {
                cout << Word << " " << "YES" << endl;
            }
            else
            {
                cout << Word << " " << "NO" << endl;
            }
        }
    }
    
    return 0;
}