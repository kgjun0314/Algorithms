#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> A(1001);
int dplis[1001];
int dplds[1001];
int maxLen;

int lis(int end)
{
	if(dplis[end] != -1)
	{
		return dplis[end];
	}
	dplis[end] = 1;
	for(int before = end - 1; before >= 0; before--)
	{
		if(A[before] < A[end])
			dplis[end] = max(dplis[end], 1 + lis(before));
	}
	return dplis[end];
}

int lds(int start)
{
	if(dplds[start] != -1)
	{
		return dplds[start];
	}
	dplds[start] = 1;
	for(int next = start + 1; next < N; next++)
	{
		if(A[start] > A[next])
			dplds[start] = max(dplds[start], 1 + lds(next));
	}
	return dplds[start];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        cin >> A[i];
    }
    memset(dplis, -1, sizeof(dplis));
	memset(dplds, -1, sizeof(dplds));
    int maxLen = 0;
	for(int begin = 0; begin < N; begin++)
	{
		lis(N - begin - 1);
		lds(begin);
	}

	for(int begin = 0; begin < N; begin++)
	{
		maxLen = max(maxLen, dplis[begin] + dplds[begin]);
	}
	
	cout << maxLen - 1 << endl;

    return 0;
}