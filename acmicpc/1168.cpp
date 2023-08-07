#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

long long N, K;
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

    cin >> N >> K;

    if(N == 1)
    {
        cout << "<1>" << endl;
        return 0;
    }

    arr.assign(N, 1);
    tree.resize(4 * N);

    init(1, 0, N - 1);
    
    int tmp = K;
    for(int i = N; i > 0; i--)
    {
        while(K > i)
            K -= i;
        long long pos = query(1, 0, N - 1, K);
        update(1, 0, N - 1, pos, -1);
        if(i == N)
            cout << "<" << pos + 1 << ", ";
        else if(i == 1)
            cout << pos + 1 << ">" << endl;
        else if(i < N)
            cout << pos + 1 << ", ";
        K += tmp - 1;
    }
    return 0;
}