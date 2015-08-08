#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int S = 1030;

int s = -1;
int b[S][S];

inline int input()
{
	char c;
	while ((c = getchar()) && (c < 48 || c > 57)) ;
	int x = c - 48;
	while ((c = getchar()) && (c > 47 && c < 58)) x = x * 10 + c - 48;
	return x;
}

void init()
{
	int i, j;
	for (i = 0; i <= s; i++)
		for (j = 0; j <= s; j++)
			b[i][j] = 0;
}

void update(int x, int y, int z)
{
	int y1;
	while (x <= s)
	{
		y1 = y;
		while (y1 <= s)
		{
			b[x][y1] += z;
			y1 += y1 & (-y1);
		}
		x += x & (-x);
	}
}

int query(int x, int y)
{
	int y1, ret = 0;
	while (x >= 1)
	{
		y1 = y;
		while (y1 >= 1)
		{
			ret += b[x][y1];
			y1 -= y1 & (-y1);
		}
		x -= x & (-x);
	}
	return ret;
}

int main()
{
	char cmd = -1;
	int x, y, x2, y2, z;
	while ((cmd = input()) && cmd != 0) ;
	while (cmd != 3)
	{
		s = input();
		init();
		while ((cmd = input()) && cmd != 0 && cmd != 3)
		{
			if (cmd == 1)
			{
				x = input(); y = input(); scanf("%d", &z);
				update(x + 1, y + 1, z);
			}
			else // if (cmd == 2)
			{
				x = input(); y = input();
				x2 = input(); y2 = input();
				++x; ++y; ++x2; ++y2;
				printf("%d\n",
					query(x2, y2)
					- query(x2, y - 1)
					- query(x - 1, y2)
					+ query(x - 1, y - 1));
			}
		}
	}
	return 0;
}