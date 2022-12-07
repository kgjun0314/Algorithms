#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, n, cnt = 0;
vector<int> tmp(500001, 0);
vector<int> A;

void merge(vector<int> &A, int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int t = 1;

    while(i <= q && j <=r)
    {
        if(A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while(i <= q)
        tmp[t++] = A[i++];
    while(j <= r)
        tmp[t++] = A[j++];
    i = p;
    t = 1;
    while(i <= r)
    {
        cnt++;
        A[i++] = tmp[t++];
        if(cnt == K)
            cout << A[i - 1] << endl;
    }
}

void merge_sort(vector<int> &A, int p, int r)
{
    if(p < r)
    {
        int q = ((p + r) / 2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    
    while(N--)
    {
        cin >> n;
        A.push_back(n);
    }

    merge_sort(A, 0, A.size() - 1);
    
    if(cnt < K)
        cout << -1 << endl;

    return 0;
}