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

int N, item, listIdx = 0;
vector<int> vec;

int biSearch(int LeftIdx, int RightIdx, int target)
{
	int MidIdx;
	while(LeftIdx < RightIdx)
	{
		MidIdx = (LeftIdx + RightIdx) / 2;

		if(vec[MidIdx] < target)
		{
			LeftIdx = MidIdx + 1;
		}
		else
		{
			RightIdx = MidIdx;
		}
	}
	return RightIdx;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		cin >> item;

		if(i == 0)
		{
			vec.push_back(item);
		}
		else if(item > vec[listIdx])
		{
			listIdx++;
			vec.push_back(item);
		}
		else
		{
			vec[biSearch(0, listIdx, item)] = item;
		}
	}

	cout << vec.size() << endl;

    return 0;
}