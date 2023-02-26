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
#include <cstdlib>
#define endl "\n"
using namespace std;

int N;
int cmd;
priority_queue<int, vector<int>, greater<int> > pq;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	while(N--)
	{
		cin >> cmd;
		if(cmd == 0)
		{
			if(pq.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(cmd);
		}
	}
	
    return 0;
}