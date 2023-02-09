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

int N, B, C;
int A[1000001];
int a;
long long cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> a;
		A[i] = a;
	}
	
	cin >> B >> C;

	for(int i = 0; i < N; i++)
	{
		if(A[i] > 0)
		{
			A[i] = A[i] - B;
			cnt++;
		}
	}

	for(int i = 0; i < N; i++)
	{
		if(A[i] > 0)
		{
			if(A[i] % C == 0)
				cnt += A[i] / C;
			else
				cnt += (A[i] / C) + 1;
		}
	}

	cout << cnt << endl;

    return 0;
}