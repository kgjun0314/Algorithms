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
int num, sum = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


	for(int i = 0; i < 5; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	for(int i = 0; i < 5; i++)
	{
		sum += vec[i];
	}

	cout << sum / vec.size() << endl;
	cout << vec[2] << endl;

    return 0;
}
