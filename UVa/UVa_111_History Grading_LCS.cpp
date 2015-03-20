#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 22

using namespace std;

int a[MAX], b[MAX], dp[MAX][MAX];

int main()
{
	int i, j, n, p;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		a[p] = i;
	}
	while (scanf("%d", &p) == 1)
	{
		memset(dp, 0, sizeof(dp));
		
		b[p] = 1;
		for (i = 2; i <= n; i++)
		{
			scanf("%d", &p);
			b[p] = i;
		}
		
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				if (a[i] == b[j])
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		
		printf("%d\n", dp[n][n]);
	}
	return 0;
}
