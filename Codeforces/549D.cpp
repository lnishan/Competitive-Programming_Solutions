#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[102][102];
int b[102][102];
int val[130];

void f(int r, int c, int v)
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			b[i][j] += v;
}

int main()
{
	int i, j, k, l, ans = 0;
	int r, c;
	val['W'] = 1; val['B'] = 0;
	scanf("%d%d", &r, &c);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf(" %c", &a[i][j]);
	f(r, c, val[a[r - 1][c - 1]]); ans++;
//	for (i = 0; i < r; i++, puts(""))
//		for (j = 0; j < c; j++)
//			putchar(b[i][j]);
	for (i = r - 1; i >= 0; i--)
		for (j = c - 1; j >= 0; j--)
			if (b[i][j] != val[a[i][j]])
			{
				f(i + 1, j + 1, val[a[i][j]] - b[i][j]);
				ans++;
			}
	printf("%d\n", ans);
	return 0;
}
