#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
using namespace std;

int C, N, K;

void josephus(int n, int k)
{
	queue<int> survivors;
	for(int i = 1; i <= n; i++)
	{
		survivors.push(i);
	}
	for(int i = 0; i < k - 1; i++)
	{
		survivors.push(survivors.front());
		survivors.pop();
	}
	cout << "<";
	while(n > 1)
	{
		cout << survivors.front() << ", ";
		survivors.pop();
		n--;
		for(int i = 0; i < k - 1; i++)
		{
			survivors.push(survivors.front());
			survivors.pop();
		}
	}

	cout << survivors.back() << ">" << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> K;
	if(N == 1)
	{
		cout << "<1>" << endl;
	}
	else
	{
		josephus(N, K);
	}
	
    return 0;
}