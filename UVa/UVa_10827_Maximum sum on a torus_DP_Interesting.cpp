#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int N = 80;

int pre[N<<1][N<<1];
int a[N<<1][N<<1];

int main()
{
	int i, j, k, l, r1, r2, c1, c2;
	int t, n, ans;
	scanf("%d", &t);
	while (t--)
	{
		ans = -INF;
		scanf("%d", &n);
		for (i = 0; i <= n; i++) pre[i][0] = pre[0][i] = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &a[i][j]);
				a[n+i][j] = a[i][n+j] = a[n+i][n+j] = a[i][j];
			}
		for (i = 1; i <= (n << 1); i++)
			for (j = 1; j <= (n << 1); j++)
				pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				for (k = 1; k <= n; k++)
					for (l = 1; l <= n; l++)
					{
						r1 = i; r2 = j;
						c1 = k; c2 = l;
						if (r2 < r1) r2 += n;
						if (c2 < c1) c2 += n;
						ans = max(ans, pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1]);
					}
		printf("%d\n", ans);
	}
	return 0;
}
