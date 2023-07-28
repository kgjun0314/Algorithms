#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define endl "\n";
using namespace std;

int T, N, A, B;
int parent[10001];
bool visit[10001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--)
    {
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            parent[i] = i;
            visit[i] = false;
        }

        for(int i = 0; i < N - 1; i++)
        {
            cin >> A >> B;
            parent[B] = A;
        }

        cin >> A >> B;
        visit[A] = true;

        while(A != parent[A])
        {
            A = parent[A];
            visit[A] = true;
        }

        while(true)
        {
            if(visit[B])
            {
                cout << B << endl;
                break;
            }
            else
            {
                visit[B] = true;
                B = parent[B];
            }
        }
    }

    return 0;
}