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
#include <set>
#define endl "\n"
using namespace std;

int K, A, B;
int large = 1;
int small = 1;
int cnt[5];
int arr[6][2];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> K;
	memset(cnt, 0, sizeof(cnt));
	memset(arr, 0, sizeof(arr));

	for(int i = 0; i < 6; i++)
	{
		cin >> A >> B;
		arr[i][0] = A;
		arr[i][1] = B;
		cnt[arr[i][0]]++;
	}

	for(int i = 0; i < 6; i++)
	{
		if(cnt[arr[i][0]] == 1)
		{
			large *= arr[i][1];
			continue;
		}
		int next = (i + 1) % 6;
		int tonext = (i + 2) % 6;
		if(arr[i][0] == arr[tonext][0])
		{
			small *= arr[next][1];
		}
	}

	cout << K * (large - small) << endl;
    return 0;
}