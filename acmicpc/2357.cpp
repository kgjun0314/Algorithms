#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N, M;
long long a, b, num;
vector<pair<long long, long long> > tree;
vector<long long> arr;

long long mininit(int node, int start, int end) 
{
    if (start == end)
        return tree[node].first = arr[start];

    int mid = (start + end) / 2;
    return tree[node].first = min(mininit(node * 2, start, mid), mininit(node * 2 + 1, mid + 1, end));
}

long long maxinit(int node, int start, int end) 
{
    if (start == end)
        return tree[node].second = arr[start];

    int mid = (start + end) / 2;
    return tree[node].second = max(maxinit(node * 2, start, mid), maxinit(node * 2 + 1, mid + 1, end));
}

long long minquery(int node, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return 1000000001;

    if (left <= start && end <= right) 
        return tree[node].first;

    int mid = (start + end) / 2;
    return min(minquery(node * 2, start, mid, left, right), minquery(node * 2 + 1, mid + 1, end, left, right));
}

long long maxquery(int node, int start, int end, int left, int right)
{
    if (right < start || left > end)
        return 0;

    if (left <= start && end <= right) 
        return tree[node].second;

    int mid = (start + end) / 2;
    return max(maxquery(node * 2, start, mid, left, right), maxquery(node * 2 + 1, mid + 1, end, left, right));
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) 
    {
        cin >> num;
        arr.push_back(num);
    }

    tree.resize(N * 4);
    mininit(1, 0, N - 1);
    maxinit(1, 0, N - 1);

    for(int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << minquery(1, 0, N - 1, a - 1, b - 1) << " " << maxquery(1, 0, N - 1, a - 1, b - 1) << endl;
    }

    return 0;
}
