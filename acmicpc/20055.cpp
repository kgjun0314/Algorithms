#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

int N, K, x, cnt = 0;
deque<int> belt;
deque<int> isOn;

void rotate()
{
	belt.push_front(belt.back());
	belt.pop_back();
	isOn.push_front(isOn.back());
	isOn.pop_back();
	if(isOn[N - 1] == true)
		isOn[N - 1] = false;
}

void move()
{
	for(int i = N - 2; i >= 0; i--)
	{
		if(isOn[i] == true && isOn[i + 1] == false && belt[i + 1] >= 1)
		{
			belt[i + 1]--;
			isOn[i] = false;
			if(i == N - 2)
				continue;
			isOn[i + 1] = true;
		}
	}
}

void newBox()
{
	if(belt[0] >= 1 && isOn[0] == false)
	{
		belt[0]--;
		isOn[0] = true;
	}
}

int countZero()
{
	int cnt = 0;
	for(int i = 0; i < belt.size(); i++)
	{
		if(belt[i] == 0)
			cnt++;
	}

	return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> K;

	for(int i = 0; i < 2 * N; i++)
	{
		cin >> x;
		belt.push_back(x);
		isOn.push_back(0);
	}

	while(1)
	{
		if(countZero() >= K)
			break;
		cnt++;
		rotate();
		move();
		newBox();
	}

	cout << cnt << endl;

    return 0;
}