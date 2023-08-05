#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N;
long long num, ans = 0;
vector<long long> tree;
vector<pair<long long, long long> > arr;

long long init(int node, int start, int end) 
{
    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

long long query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right) 
        return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, int value) 
{
    if (index < start || end < index) 
        return;

    if (start == end) 
    {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, value);
    update(node * 2 + 1, mid + 1, end, index, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) 
    {
        cin >> num;
        arr.push_back(make_pair(num, i));
    }

    tree.resize(N * 4);
    init(1, 0, N - 1);
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++)
    {
        int q = arr[i].second;
        ans += query(1, 0, N - 1, 0, q) - 1;
        update(1, 0, N - 1, q, 0);
    }

    cout << ans << endl;

    return 0;
}
