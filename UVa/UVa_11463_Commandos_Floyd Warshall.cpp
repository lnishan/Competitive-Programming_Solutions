#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int N = 102;

int dp[N][N];

int main()
{
	int i, j, cases = 0, k, t, vs, es, ans;
	int v1, v2;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%d", &vs);
		scanf("%d", &es);
		while (es--)
		{
			scanf("%d%d", &v1, &v2);
			dp[v1][v2] = dp[v2][v1] = 1;
		}
		for (k = 0; k < vs; k++)
			for (i = 0; i < vs; i++)
				for (j = 0; j < vs; j++)
					if (dp[i][k] && dp[k][j])
					{
						if (dp[i][j] == 0 || dp[i][k] + dp[k][j] < dp[i][j])
							dp[i][j] = dp[i][k] + dp[k][j];
					}
		scanf("%d%d", &v1, &v2);
		ans = dp[v1][v2];
		for (i = 0; i < vs; i++)
		{
			if (i == v1 || i == v2) continue;
			ans = max(ans, dp[v1][i] + dp[i][v2]);
		}
		printf("Case %d: %d\n", ++cases, ans);
	}
	return 0;
}
