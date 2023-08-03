#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#define endl "\n"
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    queue<int> q;
    int N, cmd, num, cnt = 1;
    string ans = "Nice";

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        q.push(num);
    }

    while(!q.empty() || !s.empty())
    {
        if(q.empty() && !s.empty())
        {
            if(s.top() == cnt)
            {
                s.pop();
                cnt++;
            }
            else if(s.top() != cnt)
            {
                ans = "Sad";
                break;
            } 
        }

        else if(!q.empty() && s.empty())
        {
            if(q.front() == cnt)
            {
                q.pop();
                cnt++;
            }
            else
            {
                s.push(q.front());
                q.pop();
            }
        }

        else if(!q.empty() && !s.empty())
        {
            int topOfStack = s.top();
            int frontOfQueue = q.front();

            if(topOfStack == cnt)
            {
                s.pop();
                cnt++;
            }
            else if(frontOfQueue == cnt)
            {
                q.pop();
                cnt++;
            }
            else
            {
                s.push(frontOfQueue);
                q.pop();
            }
        }
    }

    cout << ans << endl;

    return 0;
}