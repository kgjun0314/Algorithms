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

int N, M, num, cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;
	deque<int> dq;
	vector<int> v;
	for(int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	for(int i = 0; i < M; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for(int i = 0; i < v.size(); i++)
	{
		int leftcur = 0, rightcur = dq.size() - 1;
		for(int j = 0; j <= dq.size() / 2; j++)
		{
			if(dq[leftcur + j] == v[i])
			{
				while(dq.front() != v[i])
				{
					dq.push_back(dq.front());
					dq.pop_front();
					cnt++;
				}
				dq.pop_front();
				break;
			}
			else if(dq[rightcur - j] == v[i])
			{
				while(dq.front() != v[i])
				{
					dq.push_front(dq.back());
					dq.pop_back();
					cnt++;
				}
				dq.pop_front();
				break;
			}
		}
	}

	cout << cnt << endl;

    return 0;
}