#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <utility>
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
	deque<int> dq;
	while(N--)
	{
		cin >> cmd;
		if(cmd == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}

		else if(cmd == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if(cmd == "pop_front")
		{
			if(dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if(cmd == "pop_back")
		{
			if(dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if(cmd == "size")
		{
			cout << dq.size() << endl;
		}
		else if(cmd == "empty")
		{
			cout << dq.empty() << endl;
		}
		else if(cmd == "front")
		{
			if(dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.front() << endl;
			}
		}
		else if(cmd == "back")
		{
			if(dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.back() << endl;
			}
		}
	}
    return 0;
}