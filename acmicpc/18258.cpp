#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#define endl "\n"
using namespace std;

int N, num;
string cmd;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	queue<int> q;
	while(N--)
	{
		cin >> cmd;
		if(cmd == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if(cmd == "pop")
		{
			if(!q.empty())
			{
				cout << q.front() << endl;
				q.pop();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if(cmd == "size")
		{
			cout << q.size() << endl;
		}
		else if(cmd == "empty")
		{
			cout << q.empty() << endl;
		}
		if(cmd == "front")
		{
			if(!q.empty())
			{
				cout << q.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		if(cmd == "back")
		{
			if(!q.empty())
			{
				cout << q.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	
	}
    return 0;
}