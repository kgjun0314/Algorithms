#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <queue>
#include <cstring>
#include <set>
#define endl "\n"
using namespace std;

int N, K;
set<string> s;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> K;
        string tmp = "";
        string str = "";
        for(int j = 0; j < K; j++)
        {
            cin >> tmp;
            str += "*" + tmp;
            s.insert(str);
        }
    }

    for(string i : s)
    {
        int cnt = count(i.begin(), i.end(), '*');
        int pos = i.find_last_of('*');
        string tmp = i.substr(pos + 1);
        for(int i = 0; i < cnt - 1; i++)
        {
            cout << "--";
        }
        cout << tmp << endl;
    }

    return 0;
}