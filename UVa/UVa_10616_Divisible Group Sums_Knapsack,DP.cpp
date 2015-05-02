#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef unsigned long long LLU;

const int D = 22;
const int M = 12;
const int N = 202;

int a[N];
LLU dp[D][M], tmp[D][M]; // dp[REMAINDER][#_OF_ITEMS] = <WAYS>

int main()
{
	int i, j, k, l, cases = 0, n, q, d, m, val;
	while (scanf("%d%d", &n, &q) == 2 && (n | q))
	{
		printf("SET %d:\n", ++cases);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int qq = 1; qq <= q; qq++)
		{
			scanf("%d%d", &d, &m);
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			for (i = 0; i < n; i++)
			{
				val = ((a[i] % d) + d) % d;
				for (j = 0; j < d; j++)
					for (k = 0; k <= m; k++) // note <=
						tmp[j][k] = dp[j][k];
				for (j = 0; j < d; j++)
					for (k = 0; k < m; k++)
						tmp[ (j + val) % d ][k+1] += dp[j][k];
				for (j = 0; j < d; j++)
					for (k = 0; k <= m; k++)
						dp[j][k] = tmp[j][k];
			}
			printf("QUERY %d: %llu\n", qq, dp[0][m]);
		}
	}
	return 0;
}
