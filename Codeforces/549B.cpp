#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 105;

int fb[N], my[N];
char g[N][N];
char s[N];
int stk[N], top = 0;

int main()
{
	int i, j, k, n;
	char flag;
	scanf("%d", &n);
	fill(my+1, my+1 + n, 0);
	for (i = 1; i <= n; i++)
	{
		scanf(" ");
		gets(g[i]);
		for (j = n; j >= 1; j--)
			g[i][j] = g[i][j - 1] == '1';
	}
	for (i = 1; i <= n; i++)
		scanf("%d", &fb[i]);
//	for (i = 1; i <= n; i++, puts(""))
//		for (j = 1; j <= n; j++)
//			printf("%d ", g[i][j]);
	for (k = 0; k < n; k++)
	{
		flag = 0;
		for (i = 1; i <= n; i++)
			if (fb[i] == my[i])
			{
				flag = 1;
				stk[++top] = i;
				for (j = 1; j <= n; j++)
					if (g[i][j])
						my[j]++;
			}
		if (!flag) break;
	}
	printf("%d\n", top);
	for (i = top; i >= 1; i--)
		printf("%d\n", stk[i]);
	return 0;
}