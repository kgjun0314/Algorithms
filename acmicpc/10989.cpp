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
#include <cmath>
#include <cstdlib>
#define endl "\n"
using namespace std;

vector<int> vec;
int num;
int N;
int cnt[10001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	memset(cnt, 0, sizeof(cnt));

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		cnt[num] += 1;
	}

	for(int i = 0; i < 10001; i++)
	{
		if(cnt[i] != 0)
		{
			for(int j = 0; j < cnt[i]; j++)
			{
				cout << i << endl;
			}
		}
	}

    return 0;
}