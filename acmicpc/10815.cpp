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

int N, M, num;
vector<int> vec1;

int bs(int first, int end, int target)
{
    int mid = (first + end) / 2;
    if(first > end)
        return -1;
    else if(vec1[mid] < target)
    {
        return bs(mid + 1, end, target);
    }
    else if(target < vec1[mid])
    {
        return bs(first, mid - 1, target);
    }
    else if(target == vec1[mid])
    {
        return mid;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		vec1.push_back(num);
	}

	sort(vec1.begin(), vec1.end());

	cin >> M;

	vector<int> vec2(M);

	for(int i = 0; i < M; i++)
	{
		cin >> num;
		if(bs(0, vec1.size() - 1, num) != -1)
		{
			vec2[i] = 1;
		}
	}

	for(int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << " ";
	}

    return 0;
}