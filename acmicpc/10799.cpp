#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#define endl "\n"
using namespace std;

string st;
stack<char> s;
int cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> st;
    for(int i = 0; i < st.length(); i++)
    {
        if(st[i] == '(')
        {
            s.push(st[i]);
        }
        else
        {
            if(st[i - 1] == '(') // ()
            {
                s.pop();
                cnt = cnt + s.size();
            }
            else // ))
            {
                cnt++;
                s.pop();
            }
        }
    }

    cout << cnt << endl;

	return 0;
}