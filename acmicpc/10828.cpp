#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int N, item;
string cmd;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	stack<int> st;

	cin >> N;

	while(N--)
	{
		cin >> cmd;
		if(cmd == "push")
		{
			cin >> item;
			st.push(item);
		}
		else if(cmd == "top")
		{
			if(st.empty())
			{
				cout << -1 << endl;
			}
			else
				cout << st.top() << endl;
		}
		else if(cmd == "size")
		{
			cout << st.size() << endl;
		}
		else if(cmd == "empty")
		{
			cout << st.empty() << endl;
		}
		else if(cmd == "pop")
		{
			if(st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
	}
	
    return 0;
}