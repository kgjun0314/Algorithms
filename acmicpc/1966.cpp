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

int C, N, M, num;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> C;

	while(C--)
	{
		cin >> N >> M;
		queue<pair<int, int> > q;
		priority_queue<int> pq;
		for(int i = 0; i < N; i++)
		{
			cin >> num;
			q.push(make_pair(i, num));
			pq.push(num);
		}

		int order = 0;
		bool flag = false;
		
		while(!flag)
		{
			if(pq.top() == q.front().second)
			{
				order++;
				if(q.front().first == M)
				{
					flag = true;
				}
				else
				{
					q.pop();
					pq.pop();
				}
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
		cout << order << endl;
	}
    return 0;
}