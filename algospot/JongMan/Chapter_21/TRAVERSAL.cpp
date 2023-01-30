#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#define endl "\n"
using namespace std;

int C, N, item;

vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int> inorder)
{
	const int N = preorder.size();
	if(preorder.empty())
	{
		return;
	}
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - 1 - L;

	printPostOrder(slice(preorder, 1, 1 + L), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << " ";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> C;
	while(C--)
	{
		cin >> N;
		vector<int> preorder, inorder;
		for(int i = 0; i < N; i++)
		{
			cin >> item;
			preorder.push_back(item);
		}
		for(int i = 0; i < N; i++)
		{
			cin >> item;
			inorder.push_back(item);
		}
		printPostOrder(preorder, inorder);
		cout << endl;
	}

    return 0;
}