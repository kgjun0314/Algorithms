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

int N, num;
double sum = 0;
vector<int> vt;
vector<int> cnt(8001);

int mode()
{
	int max = 0, idx;
	bool flag = false;
	for(int i = 0; i < N; i++)
	{
		if(cnt[vt[i] + 4000] > max)
		{
			max = cnt[vt[i] + 4000];
		}
	}
	for(int i = 0; i < 8001; i++)
	{
		if(cnt[i] == max)
		{
			if(!flag)
			{
				idx = i;
				flag = !flag;
			}
			else if(flag)
			{
				idx = i;
				break;
			}
		}
	}
	return idx - 4000;
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
		vt.push_back(num);
		cnt[num + 4000]++;
		sum += num;
	}

	sort(vt.begin(), vt.end());
	int mid = vt[N / 2];
	int mode_val = mode();
	int max_val = *max_element(vt.begin(), vt.end());
	int min_val = *min_element(vt.begin(), vt.end());
	int range = max_val - min_val;

	if(round(sum / N) == -0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << round(sum / N) << endl;
	}
	cout << mid << endl;
	cout << mode_val << endl;
	cout << range << endl;

    return 0;
}