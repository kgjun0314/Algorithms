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
		if(vec1[lower_bound(vec1.begin(), vec1.end(), num) - vec1.begin()] == num)
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