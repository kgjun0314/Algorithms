#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <sstream>
#define endl "\n"
using namespace std;

struct Node {
	int key;
	int priority, size;

	Node* left, * right;
	Node(int _key) : key(_key), priority(rand()), size(1), left(nullptr), right(nullptr) {}

	void calcSize() 
	{
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}

	void setLeft(Node* newLeft) 
	{
		left = newLeft; calcSize(); 
	}

	void setRight(Node* newRight) 
	{
		right = newRight; calcSize(); 
	}
};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, int key) 
{
	if (root == nullptr)
	{
		return NodePair(nullptr, nullptr);
	}

	if (root->key > key) 
	{
		NodePair L = split(root->left, key);
		root->setLeft(L.second);
		return NodePair(L.first, root);
	}

	else 
	{
		NodePair R = split(root->right, key);
		root->setRight(R.first);
		return NodePair(root, R.second);
	}
}

Node* insert(Node* root, Node* node)
{
	if (root == nullptr) return node;

	if (root->priority < node->priority) 
	{
		NodePair ret = split(root, node->key);
		node->setLeft(ret.first);
		node->setRight(ret.second);
		return node;
	}

	else if (root->key > node->key)
	{
		root->setLeft(insert(root->left, node));
	}

	else 
	{
		root->setRight(insert(root->right, node));
	}

	return root;
}

Node* merge(Node* a, Node* b) {
	if (a == nullptr) return b;
	if (b == nullptr) return a;

	if (a->priority > b->priority) {
		a->setRight(merge(a->right, b));
		return a;
	}
	b->setLeft(merge(a, b->left));
	return b;
}

Node* erase(Node* root, int key) {
	if (root == nullptr) return nullptr;

	if (root->key > key) 
	{
		root->setLeft(erase(root->left, key));
	}
	else if (root->key < key) 
	{
		root->setRight(erase(root->right, key));
	}

	else 
	{
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	return root;
}

Node* kth(Node* root, int k) {
	if (root == nullptr) return nullptr;

	int leftSize = 0;
	if (root->left) leftSize = root->left->size;

	if (leftSize > k - 1) return kth(root->left, k);
	else if (leftSize == k - 1) return root;
	else return kth(root->right, k - (leftSize + 1));
}

int C, N, shifted[50000];
int A[50000];

void solve()
{
	Node* candidates = NULL;
	for(int i = 0; i < N; i++)
	{
		candidates = insert(candidates, new Node(i + 1));
	}
	for(int i = N - 1; i >= 0; i--)
	{
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k -> key;
		candidates = erase(candidates, k -> key);
	}
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
		for(int i = 0; i < N; i++)
		{
			cin >> shifted[i];
		}
		solve();
		for(int i = 0; i < N; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}

    return 0;
}