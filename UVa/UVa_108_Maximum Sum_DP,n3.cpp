#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 2147483647

using namespace std;

const int N = 105;

// number from 1 to N
int max2D(int (&a)[N][N], const int &r, const int &c)
{
	int i, j, k, m, s, ret = -INF;
	static int pre[N][N];
	for (i = 1; i <= r; i++) pre[i][0] = 0;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			pre[i][j] = pre[i][j-1] + a[i][j];
	for (i = 1; i <= c; i++)
		for (j = i; j <= c; j++)
		{
			m = s = 0;
			for (k = 1; k <= r; k++)
			{
				s += pre[k][j] - pre[k][i-1];
				ret = max(ret, s-m);
				m = min(m, s);
			}
		}
	return ret;
}

int a[N][N];
int main()
{
	int i, j, r, c;
	while (scanf("%d", &r) == 1)
	{
		c = r;
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", max2D(a, r, c));
	}
	return 0;
}
