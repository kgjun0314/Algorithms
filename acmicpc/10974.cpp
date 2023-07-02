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

int N;
int arr[9];
bool visited[9];
vector<int> vec;

void printperm(int cnt)
{
	if(cnt == N)
	{
		for(int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
		return;
	}

	for(int i = 0; i < N; i++)
	{
		if(visited[i])
		{
			continue;
		}
		visited[i] = true;
		vec.push_back(arr[i]);
		printperm(cnt + 1);
		vec.pop_back();
		visited[i] = false;
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
		arr[i] = i + 1;
		visited[i] = false;
	}

	printperm(0);

    return 0;
}