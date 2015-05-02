#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int N = 52;

int dp[N][N];
int d[N];

int main()
{
	int i, j, k, l, n;
	while (scanf("%d", &l) == 1 && l)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		d[0] = 0;
		d[n+1] = l;
		
		for (i = 0; i <= n; i++) dp[i][i] = 0;
		for (i = 1; i <= n; i++) // i = interval length
			for (j = n-i; j >= 0; j--)
			{
				int ub = j + i;
				int &cur = dp[j][ub];
				cur = INF;
				for (k = j; k < ub; k++)
					cur = min(cur, dp[j][k] + dp[k+1][ub]);
				cur += d[ub+1] - d[j];
			}
		
		printf("The minimum cutting is %d.\n", dp[0][n]);
	}
	return 0;
}
