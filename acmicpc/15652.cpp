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
#include <cmath>
#define endl "\n"
using namespace std;

int arr[9];
vector<int> vec;
int N, M;

void backtracking(int low, int cnt)
{
	if(cnt == M)
	{
		for(int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
		return;
	}

	for(int i = low; i < N; i++)
	{
		vec.push_back(arr[i]);
		backtracking(i, cnt + 1);
		vec.pop_back();
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	backtracking(0, 0);

    return 0;
}
