#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 102;

char g[N][N], t[N][N];

int judge(const char &a, const char &b)
{
	if (a == 'R')
	{
		if (b == 'S')
			return 1;
		else if (b == 'P')
			return -1;
		else
			return 0;
	}
	else if (a == 'S')
	{
		if (b == 'P')
			return 1;
		else if (b == 'R')
			return -1;
		else
			return 0;
	}
	else
	{
		if (b == 'R')
			return 1;
		else if (b == 'S')
			return -1;
		else
			return 0;
	}
}

int r, c, n;

inline bool valid(const int &x, const int &y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

int main()
{
	int i, j, k, tt;
	int i2, j2, ret;
	cin >> tt;
	while (tt--)
	{
		scanf("%d%d%d ", &r, &c, &n);
		for (i = 0; i < r; i++)
			gets(g[i]);
		for (k = 0; k < n; k++)
		{
			for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
					t[i][j] = g[i][j];
			for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
				{
					i2 = i + 1; j2 = j;
					if (valid(i2, j2))
					{
						ret = judge(g[i][j], g[i2][j2]);
						if (ret == 1)
							t[i2][j2] = g[i][j];
						else if (ret == -1)
							t[i][j] = g[i2][j2];
					}
					
					i2 = i; j2 = j + 1;
					if (valid(i2, j2))
					{
						ret = judge(g[i][j], g[i2][j2]);
						if (ret == 1)
							t[i2][j2] = g[i][j];
						else if (ret == -1)
							t[i][j] = g[i2][j2];
					}
				}
			for (i = 0; i < r; i++)
				for (j = 0; j < c; j++)
					g[i][j] = t[i][j];
		}
		for (i = 0; i < r; i++, puts(""))
			for (j = 0; j < c; j++)
				putchar(g[i][j]);
		if (tt) puts("");
	}

}