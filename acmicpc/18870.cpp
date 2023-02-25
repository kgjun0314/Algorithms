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

int N;
int num;
int cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	vector<pair<int, int> > vec(N);
	vector<int> pressed(N, 0);

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		vec[i].first = num;
		vec[i].second = i;
	}

	sort(vec.begin(), vec.end());

	for(int i = 1; i < N; i++)
	{
		if(vec[i].first != vec[i - 1].first)
		{
			pressed[vec[i].second] = i - cnt;
		}
		else
		{
			pressed[vec[i].second] = pressed[vec[i - 1].second];
			cnt++;
		}	
	}

	for(int i = 0; i < N; i++)
	{
		cout << pressed[i] << " ";
	}

	cout << endl;
    return 0;
}