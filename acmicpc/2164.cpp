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

int N;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	queue<int> q;
	for(int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	if(q.size() == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	while(true)
	{
		q.pop();
		if(q.size() == 1)
		{
			break;
		}
		q.push(q.front());
		q.pop();
		if(q.size() == 1)
		{
			break;
		}
	}

	cout << q.front() << endl;

    return 0;
}