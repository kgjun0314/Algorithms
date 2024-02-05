#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
#include <stack>
#define endl '\n'
using namespace std;
void init()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

string S, T;
int flag = 0;

void append_A();
void pop_A();
void append_B();
void pop_B();

void input()
{
	cin >> S;
	cin >> T;
}

void append_A()
{
	T = T + "A";
}

void pop_A()
{
	T = T.substr(0, T.length() - 1);
}

void append_B()
{
	T = T + "B";
	reverse(T.begin(), T.end());
}

void pop_B()
{
	T = T.substr(1, T.length() - 1);
	reverse(T.begin(), T.end());
}

void solve()
{
	if(S.length() == T.length())
	{
		if(S == T)
		{
			cout << 1 << endl;
			exit(0);
		}
	}
	if(T[T.length() - 1] == 'A')
	{
		pop_A();
		solve();
		append_A();
	}
	if(T[0] == 'B')
	{
		pop_B();
		solve();
		append_B();
	}
}

int main()
{
    init();
	input();
	solve();
	cout << 0 << endl;

	return 0;
}