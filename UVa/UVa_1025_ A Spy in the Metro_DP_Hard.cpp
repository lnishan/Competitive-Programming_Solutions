#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 52
#define M 52
#define T 202
#define INF 0x3fffffff

using namespace std;

int elap[N];
int f[M], r[M];
int fs[M][N], bs[M][N];
int dp[T][N]; // dp[i][j] = minimum waiting time, at time i, at station j.

int main()
{
	int i, j, k, l, n, t, m1, m2, cases = 0;
	while (scanf("%d", &n) == 1 && n > 0)
	{
		scanf("%d", &t);
		
		// init
		for (i = 0; i <= t; i++)
			for (j = 0; j < n; j++)
				dp[i][j] = INF;
		
		// input
		for (i = 1; i < n; i++)
			scanf("%d", &elap[i]);
		scanf("%d", &m1);
		for (i = 0; i < m1; i++)
		{
			scanf("%d", &fs[i][0]);
			for (j = 1; j < n; j++)
				fs[i][j] = fs[i][j-1] + elap[j]; // create table for forward-bound trains
		}
		scanf("%d", &m2);
		for (i = 0; i < m2; i++)
		{
			scanf("%d", &bs[i][n-1]);
			for (j = n-2; j >= 0; j--)
				bs[i][j] = bs[i][j+1] + elap[j+1];
		}
		
		// station 0 is reachable at starting time (wait until departure
		for (i = 0; i < m1; i++)
			dp[ fs[i][0] ][0] = fs[i][0];
		
		for (i = 0; i <= t; i++)
			for (j = 0; j < n; j++)
			// check for trains reachable to station j at i
			{
				if (i == 0 && j == 0) continue;
				
				// itself
				if (i > 0 && dp[i-1][j] != INF)
					dp[i][j] = dp[i-1][j] + 1;
				
				// forward
				if (j > 0)
					for (k = 0; k < m1 && fs[k][j] <= i; k++)
						if (dp[ fs[k][j-1] ][j-1] != INF) // been here ?
							dp[i][j] = min(dp[i][j], dp[ fs[k][j-1] ][j-1] + /*wait time*/ i - fs[k][j]);
				
				// backward
				if (j < n-1)
					for (k = 0; k < m2 && bs[k][j] <= i; k++)
						if (dp[ bs[k][j+1] ][j+1] != INF) // been here ?
							dp[i][j] = min(dp[i][j], dp[ bs[k][j+1] ][j+1] + /*wait time*/ i - bs[k][j]);
			}
		printf("Case Number %d: ", ++cases);
		if (dp[t][n-1] == INF)
			puts("impossible");
		else
			printf("%d\n", dp[t][n-1]);
	}
	return 0;
}
