#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
#include <stack>
#define endl "\n";
using namespace std;

int N, M, K, a, b, c, idx, head, tail;
long long x, value;
long long arr[1000001], tree[1000001];

long long prefixSum(int i)
{
    long long result = 0;
    while(i > 0)
    {
        result += tree[i];
        i -= (i & -i);
    }
    return result;
}

void update(int i, long long dif)
{
    while(i <= N)
    {
        tree[i] += dif;
        i += (i & -i);
    }
}

long long intervalSum(int tail, int head)
{
    return prefixSum(head) - prefixSum(tail - 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++)
    {
        cin >> x;
        arr[i] = x;
        update(i, x);
    }
    int count = M + K;
    while(count--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            cin >> idx >> value;
            update(idx, value - arr[idx]);
            arr[idx] = value;
        }
        else
        {
            cin >> tail >> head;
            cout << intervalSum(tail, head) << endl;
        }
    }
    
    return 0;
}