#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 102;
int vlist[N];
int idx[N];
int dp[N][N];

int main()
{
	int i, j, k, vs, v1, v2, tot, cases = 0;
	char inp;
	do
	{
		tot = 0;
		inp = 0;
		vs = 0;
		memset(idx, -1, sizeof(idx));
		memset(dp, -1, sizeof(dp));
		while (scanf("%d%d", &v1, &v2) && (v1 | v2))
		{
			inp = 1;
			if (idx[v1] == -1) { idx[v1] = vs; vlist[vs++] = v1; }
			if (idx[v2] == -1) { idx[v2] = vs; vlist[vs++] = v2; }
			int &i1 = idx[v1];
			int &i2 = idx[v2];
			dp[i1][i2] = 1;
		}
		if (!inp) break;
		for (k = 0; k < vs; k++)
			for (i = 0; i < vs; i++)
				for (j = 0; j < vs; j++)
					if (dp[i][k] != -1 && dp[k][j] != -1)
					{
						if (dp[i][j] == -1 || dp[i][k] + dp[k][j] < dp[i][j])
							dp[i][j] = dp[i][k] + dp[k][j];
					}
		for (i = 0; i < vs; i++)
			for (j = 0; j < vs; j++)
			{
				if (i == j) continue;
				tot += dp[i][j];
			}
		printf("Case %d: average length between pages = %.3f clicks\n", ++cases, double(tot) / (vs * (vs - 1)));
	} while (inp);
	return 0;
}
