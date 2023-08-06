#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int T, N, K, Q, A, B;
vector<pair<int, int> > tree;
vector<int> arr;

int mininit(int node, int start, int end)
{
    if(start == end)
        return tree[node].first = arr[start];
    else
    {
        int mid = (start + end) / 2;
        return tree[node].first = min(mininit(node * 2, start, mid), mininit(node * 2 + 1, mid + 1, end));
    }
}

int maxinit(int node, int start, int end)
{
    if(start == end)
        return tree[node].second = arr[start];
    else
    {
        int mid = (start + end) / 2;
        return tree[node].second = max(maxinit(node * 2, start, mid), maxinit(node * 2 + 1, mid + 1, end));
    }
}

int minquery(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
        return 100001;
    if(left <= start && end <= right)
        return tree[node].first;
    
    int mid = (start + end) / 2;
    return min(minquery(node * 2, start, mid, left, right), minquery(node * 2 + 1, mid + 1, end, left, right));
}

int maxquery(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node].second;
    
    int mid = (start + end) / 2;
    return max(maxquery(node * 2, start, mid, left, right), maxquery(node * 2 + 1, mid + 1, end, left, right));
}

int minupdate(int node, int start, int end, int index, int value)
{
    if(index < start || end < index)
        return tree[node].first;

    if(start == end)
        return tree[node].first = value;
    
    int mid = (start + end) / 2;
    return tree[node].first = min(minupdate(node * 2, start, mid, index, value), minupdate(node * 2 + 1, mid + 1, end, index, value));
}

int maxupdate(int node, int start, int end, int index, int value)
{
    if(index < start || end < index)
        return tree[node].second;

    if(start == end)
        return tree[node].second = value;
    
    int mid = (start + end) / 2;
    return tree[node].second = max(maxupdate(node * 2, start, mid, index, value), maxupdate(node * 2 + 1, mid + 1, end, index, value));
}


int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while(T--)
    {
        tree.clear();
        arr.clear();

        cin >> N >> K;

        for(int i = 0; i < N; i++)
        {
            arr.push_back(i);
        }

        tree.resize(4 * N);
        mininit(1, 0, N - 1);
        maxinit(1, 0, N - 1);

        while(K--)
        {
            cin >> Q >> A >> B;
            if(Q == 0)
            {
                int a = minquery(1, 0, N - 1, A, A);
                int b = minquery(1, 0, N - 1, B, B);
                minupdate(1, 0, N - 1, A, b);
                maxupdate(1, 0, N - 1, A, b);
                minupdate(1, 0, N - 1, B, a);
                maxupdate(1, 0, N - 1, B, a);
            }
            else if(Q == 1)
            {
                if(minquery(1, 0, N - 1, A, B) == A && maxquery(1, 0, N - 1, A, B) == B)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }

    return 0;
}
