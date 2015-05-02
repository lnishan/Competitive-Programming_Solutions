#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int N = 10002;
const int M = 1000002;

int coin[N];
int dp[M];

int main()
{
	int i, j, k, t, m, n, tot;
	scanf("%d", &t);
	while (t--)
	{
		tot = 0;
		scanf("%d", &m);
		scanf("%d", &n);
		for (i = 0; i < n; tot += coin[i], i++)
			scanf("%d", &coin[i]);
		fill(dp + 1, dp + 1 + tot, INF);
		dp[0] = 0;
		for (i = 0; i < n; i++)
			for (j = tot; j >= coin[i]; j--)
				if (dp[j - coin[i]] != INF)
					dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		for (i = m; i <= tot; i++)
			if (dp[i] != INF)
			{
				printf("%d %d\n", i, dp[i]);
				break;
			}
	}
	return 0;
}
