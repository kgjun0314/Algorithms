#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

int N, M, flag;
int minCityDist = INT_MAX;

struct House{
	int r;
	int c;
};

struct Chicken{
	int r;
	int c;
	bool visited;
};

vector<House> house;
vector<Chicken> chicken;

void calculateDist()
{
	int cityDist = 0;
	for(int i = 0; i < house.size(); i++)
	{
		int minHouseDist = INT_MAX;
		for(int j = 0; j < chicken.size(); j++)
		{
			if(chicken[j].visited)
			{
				int houseDist = abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c);
				if(houseDist < minHouseDist)
				{
					minHouseDist = houseDist;
				}
			}
		}
		cityDist += minHouseDist;
	}
	if(cityDist < minCityDist)
	{
		minCityDist = cityDist;
	}
}

void selectChicken(int index, int count)
{
	if(count == M)
	{
		calculateDist();
	}
	for(int i = index; i < chicken.size(); i++)
	{
		if(!chicken[i].visited)
		{
			chicken[i].visited = true;
			selectChicken(i, count + 1);
			chicken[i].visited = false;
		}
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> flag;
			if(flag == 1)
			{
				House h;
				h.r = i;
				h.c = j;
				house.push_back(h);
			}
			else if(flag == 2)
			{
				Chicken c;
				c.r = i;
				c.c = j;
				c.visited = false;
				chicken.push_back(c);
			}
		}
	}
	
	selectChicken(0, 0);

	cout << minCityDist << endl;

    return 0;
}