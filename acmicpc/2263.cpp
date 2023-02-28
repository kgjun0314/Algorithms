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
int num;
vector<int> inorder;
vector<int> postorder;

void printPreOrder(int post_s, int post_e, int in_s, int in_e)
{
	int root = postorder[post_e];
	cout << root << " ";

	if(in_s == in_e)
	{
		return;
	}

	int in_l = 0;

	for(int i = in_s; i <= in_e; i++)
	{
		if(inorder[i] == root)
		{
			in_l = i - 1;
			break;
		}
	}

	if(in_l >= in_s)
	{
		printPreOrder(post_s, post_s + (in_l - in_s), in_s, in_l);
	}

	int in_r = in_l + 2;
	
	if(in_r <= in_e)
	{
		printPreOrder(post_s + (in_l - in_s) + 1, post_e - 1, in_r, in_e);
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		inorder.push_back(num);
	}

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		postorder.push_back(num);
	}

	printPreOrder(0, N - 1, 0, N - 1);

	cout << endl;

    return 0;
}