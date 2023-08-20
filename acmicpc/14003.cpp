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

long long N, item, listIdx = 0;
vector<long long> vec;
vector<long long> lis;
vector<long long> idx;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

    vec.resize(N);
    idx.assign(N, -1);

    for(int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
	
	for(long long i = 0; i < N; i++)
	{
		if(lis.empty() || vec[i] > lis.back())
		{
			lis.push_back(vec[i]);
            idx[i] = lis.size() - 1;
		}
		else
		{
            auto it = lower_bound(lis.begin(), lis.end(), vec[i]);
            *it = vec[i];
            idx[i] = distance(lis.begin(), it);
		}
	}

	int lisLength = lis.size();
    cout << lisLength << endl;

    vector<int> result;
    for (int i = N - 1; i >= 0; --i) 
    {
        if (idx[i] == lisLength - 1) 
        {
            result.push_back(vec[i]);
            --lisLength;
        }
    }

    for (int i = result.size() - 1; i >= 0; --i) 
    {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}