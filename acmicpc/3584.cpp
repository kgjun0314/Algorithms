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
bool visited[10001];

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
            visited[i] = false;
        }

        for(int i = 0; i < N - 1; i++)
        {
            cin >> A >> B;
            parent[B] = A;
        }

        cin >> A >> B;
        visited[A] = true;

        while(A != parent[A])
        {
            A = parent[A];
            visited[A] = true;
        }

        while(true)
        {
            if(visited[B])
            {
                cout << B << endl;
                break;
            }
            else
            {
                visited[B] = true;
                B = parent[B];
            }
        }
    }

    return 0;
}