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
#include <cstdlib>
#define endl "\n"
using namespace std;

int N;
char p, c1, c2;
vector<vector<char> > tree(27);

void preorder(char root)
{
	if(root == '.')
	{
		return;
	}
	cout << root;
	preorder(tree[root - 'A'][0]);
	preorder(tree[root - 'A'][1]);
}

void inorder(char root)
{
	if(root == '.')
	{
		return;
	}
	inorder(tree[root - 'A'][0]);
	cout << root;
	inorder(tree[root - 'A'][1]);
}

void postorder(char root)
{
	if(root == '.')
	{
		return;
	}
	postorder(tree[root - 'A'][0]);
	postorder(tree[root - 'A'][1]);
	cout << root;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> p >> c1 >> c2;
		tree[p - 'A'].push_back(c1);
		tree[p - 'A'].push_back(c2);
	}

	preorder('A');
	cout << endl;

	inorder('A');
	cout << endl;

	postorder('A');
	cout << endl;


    return 0;
}