#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

long long N, M, Q, i, j, k, num;
vector<long long> tree;
vector<long long> arr;
vector<long long> lazy;

long long init(long long node, long long start, long long end)
{
    if(start == end)
        return tree[node] = arr[start];

    long long mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void lazyUpdate(long long node, long long start, long long end)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(long long node, long long start, long long end, long long left, long long right, long long value)
{
    lazyUpdate(node, start, end);

    if(end < left || right < start)
        return;

    if(left <= start && end <= right)
    {
        tree[node] += (end - start + 1) * value;
        if(start != end)
        {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }

    long long mid = (start + end) / 2;
    updateRange(node * 2, start, mid, left, right, value);
    updateRange(node * 2 + 1, mid + 1, end, left, right, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(long long node, long long start, long long end, long long left, long long right)
{
    lazyUpdate(node, start, end);

    if(end < left || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    
    long long mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}


int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    arr.resize(N);

    for(long long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    tree.resize(4 * N);
    lazy.resize(4 * N);
    init(1, 0, N - 1);

    cin >> M;
    while(M--)
    {
        cin >> Q;
        if(Q == 1)
        {
            cin >> i >> j >> k;
            updateRange(1, 0, N - 1, i - 1, j - 1, k);
        }
        else if(Q == 2)
        {
            cin >> i;
            cout << query(1, 0, N - 1, i - 1, i - 1) << endl;
        }
    }

    return 0;
}