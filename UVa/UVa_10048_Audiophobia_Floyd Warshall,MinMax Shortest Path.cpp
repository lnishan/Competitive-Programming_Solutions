#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int V = 102;

int dp[V][V];

int main()
{
	int i, j, k;
	int v, e, q;
	int v1, v2, wt;
	int cases = 0;
	while (scanf("%d%d%d", &v, &e, &q) == 3 && (v | e | q))
	{
		for (i = 1; i <= v; i++) for (j = 1; j <= v; j++) dp[i][j] = INF;
		while (e--)
		{
			scanf("%d%d%d", &v1, &v2, &wt);
			dp[v1][v2] = min(dp[v1][v2], wt);
			dp[v2][v1] = min(dp[v2][v1], wt);
		}
		for (k = 1; k <= v; k++)
			for (i = 1; i <= v; i++)
				for (j = 1; j <= v; j++)
					if ( (wt = max(dp[i][k], dp[k][j])) < dp[i][j])
						dp[i][j] = wt;
		if (cases) puts("");
		printf("Case #%d\n", ++cases);
		while (q--)
		{
			scanf("%d%d", &v1, &v2);
			if (dp[v1][v2] == INF)
				puts("no path");
			else
				printf("%d\n", dp[v1][v2]);
		}
	}
	return 0;
}
