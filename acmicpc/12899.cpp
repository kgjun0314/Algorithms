#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

long long N, T, X;
vector<long long> tree;
vector<long long> arr;

long long init(long long node, long long start, long long end)
{
    if(start == end)
        return tree[node] = arr[start];

    long long mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long update(long long node, long long start, long long end, long long index, long long value)
{
    if(index < start || end < index)
        return tree[node];

    if(start == end)
    {
        return tree[node] += value;
    }

    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, index, value) + update(node * 2 + 1, mid + 1, end, index, value);
}

long long query(long long node, long long start, long long end, long long rank)
{
    if (start == end) 
        return start;
    else 
    {
        int mid = (start + end) / 2;
        if(tree[node * 2] >= rank)
            return query(node * 2, start, mid, rank);
        else 
            return query(node * 2 + 1, mid + 1, end, rank - tree[node * 2]);
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    arr.assign(2000002, 0);
    tree.resize(4 * 2000002);

    init(1, 0, 2000002);

    while(N--)
    {
        cin >> T >> X;
        if(T == 1)
        {
            update(1, 0, 2000002, X - 1, 1);
        }
        else if(T == 2)
        {
            long long pos = query(1, 0, 2000002, X);
            update(1, 0, 2000002, pos, -1);
            cout << pos + 1 << endl;
        }
    }
    return 0;
}