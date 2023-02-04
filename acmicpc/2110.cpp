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

int N, C, item, listIdx = 0;
vector<int> vec;

int BS(int Left, int Right)
{
	int result = 0;
	while(Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		int cnt = 1;
		int pre = vec[0];

		for(int i = 1; i < N; i++)
		{
			if(vec[i] - pre >= Mid)
			{
				cnt++;
				pre = vec[i];
			}
		}

		if(cnt < C)
		{
			Right = Mid - 1;
		}

		else
		{
			result = Mid;
			Left = Mid + 1;
		}
	}
	return result;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> C;

	for(int i = 0; i < N; i++)
	{
		cin >> item;
		vec.push_back(item);
	}

	sort(vec.begin(), vec.end());

	int left = 1;
	int right = vec[N - 1] - vec[0];

	cout << BS(left, right) << endl;

    return 0;
}