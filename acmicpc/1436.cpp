#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int series = 0;
int name = 666;

int Findseries(int N)
{
    while(1)
    {
        string target = to_string(name);
        for(int j = 0; j < target.length() - 2; j++)
        {
            if(target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')
            {
                series++;
                if(series == N)
                    return name;
                break;
            }
        }
        name++;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    cout << Findseries(N);
    
    return 0;
}