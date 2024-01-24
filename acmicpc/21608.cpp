#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <deque>
using namespace std;

int student[401][4];
int map[21][21];
int N;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Info{
	int r;
	int c;
	int empty;
	int match;
};

bool isValid(int r, int c)
{
	return (1 <= r && r <= N && 1 <= c && c <= N);
}

bool compare(Info a, Info b)
{
	if(a.match == b.match)
	{
		if(a.empty == b.empty)
		{
			if(a.c == b.c)
				return a.r < b.r;
			return a.c < b.c;
		}
		return a.empty > b.empty;
	}
	return a.match > b.match;
}

Info bfs(int key, int r, int c)
{
	Info tmp = {r, c, 0, 0};
	for(int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(!isValid(nr, nc))
			continue;
		if(map[nr][nc] == 0)
		{
			tmp.empty++;
			continue;
		}
		for(int j = 0; j < 4; j++)
		{
			if(student[key][j] == map[nr][nc])
				tmp.match++;
		}
	}
	return tmp;
}

void matching(int key){
    vector<Info> list;
    for(int i = 1; i <= N; i++)
	{
        for(int j = 1; j <= N; j++)
		{
            if(map[i][j] == 0) 
				list.push_back(bfs(key,i,j));
        }
    }

    sort(list.begin(),list.end(),compare);
    map[list[0].r][list[0].c] = key;
}

int getScore(){
    int sum = 0;
    for(int k = 1; k <= N * N; k++)
	{
        for(int i = 1; i <= N; i++)
		{
            bool endFlag = false;
            for(int j = 1; j <= N; j++)
			{
                if(map[i][j] == k)
				{
                    Info tmp = bfs(k, i, j);
                    sum += pow(10, tmp.match - 1);
                    endFlag = true;
                    break;
                }
            }
            if(endFlag) break;
        }
    }
    return sum;
}

int main(){
    cin >> N;
    vector<int> order;
    for(int i = 1; i <= N * N; i++)
	{
        int key;
        cin >> key;
        order.push_back(key);
        for(int j = 0; j < 4; j++)
		{
            int num;
            cin >> num;
            student[key][j] = num;
        }
    }
    
    for(int i = 0; i < order.size(); i++)
	{
        matching(order[i]);
    }

    cout << getScore() << "\n";

	return 0;
}