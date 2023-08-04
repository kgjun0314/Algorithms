#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

const int MOD = 1000000007;

int N, M, K, cmd, b;
long long num, c;
vector<long long> tree;
vector<long long> arr;

long long init(int node, int start, int end) 
{
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long query(int node, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return 0;

    if (left <= start && end <= right) 
        return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

long long update(int node, int start, int end, int index, long long value) 
{
    if (index < start || index > end) 
        return tree[node];

    if (start == end) 
        return tree[node] = value;

    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, index, value) + update(node * 2 + 1, mid + 1, end, index, value);
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) 
    {
        cin >> num;
        arr.push_back(num);
    }

    tree.resize(N * 4);
    init(1, 0, N - 1);

    for (int i = 0; i < M + K; ++i) 
    {
        cin >> cmd >> b >> c;
        if (cmd == 1) 
            update(1, 0, N - 1, b - 1, c);
        else if (cmd == 2) 
            cout << query(1, 0, N - 1, b - 1, c - 1) << endl;
    }

    return 0;
}
