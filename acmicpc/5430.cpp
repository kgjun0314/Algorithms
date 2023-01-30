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

int T, arysize;
string fname, ary;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> T;

	while(T--)
	{
		bool REVflag = false, ERflag = false;

		cin >> fname;
		cin >> arysize;
		cin >> ary;
		
		ary.resize(ary.length() - 1);
		ary.erase(ary.begin());
		deque<int> dq;

		for(int i = 0; i < ary.length(); i++)
		{
			if(arysize > 0 && ary[i] != ',')
			{
				dq.push_back(atoi(&ary[i]));
				for(int j = 0; j < 2; j++)
				{
					if(ary[i + 1] != ',')
					{
						i++;
					}
				}
			}
		}

		for(int i = 0; i < fname.length(); i++)
		{
			int cnt = 0;
			if(fname[i] == 'R')
			{
				REVflag = !REVflag;
			}
			else if(fname[i] == 'D')
			{
				if(dq.empty())
				{
					ERflag = true;
					break;
				}
				if(REVflag == true)
					dq.pop_back();
				else if(REVflag == false)
					dq.pop_front();
			}
		}

		if(ERflag == true)
		{
			cout << "error" << endl;		
		}

		else if (dq.empty())
            cout << "[]" << endl;

		else if(REVflag == false)
		{
			cout << "[";
			while(dq.size() > 1)
			{
				cout << dq.front() << ",";
				dq.pop_front();
			}
			cout << dq.front() << "]" << endl;
		}

		else if(REVflag == true)
		{
			cout << "[";
			while(dq.size() > 1)
			{
				cout << dq.back() << ",";
				dq.pop_back();
			}
			cout << dq.back() << "]" << endl;
		}
	}
    return 0;
}