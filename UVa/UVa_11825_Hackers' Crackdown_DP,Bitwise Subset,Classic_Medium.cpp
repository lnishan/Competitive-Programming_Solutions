#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 16

using namespace std;

int aff[N]; // aff[i] = computers affected by computer i
int dpAff[1 << N]; // dpAff[10010] = computers affected by computer 1, 4
int dp[1 << N]; // dp[10111] = maximum service taken down if we choose computers 0,1,2,4

int main()
{
	int i, j, k, cases = 0, n, vs, vi, all, sub, res;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(aff, 0, sizeof(aff));
		memset(dpAff, 0, sizeof(dpAff));
		memset(dp, 0, sizeof(dp));
		all = (1 << n) - 1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &vs);
			aff[i] = 1 << i;
			while (vs--)
			{
				scanf("%d", &vi);
				aff[i] |= (1 << vi);
			}
		}
		for (i = 1; i <= all; i++) // i = computer
		{
			res = i;
			for (j = 0; res; res >>= 1, j++)
				if (res & 1)
					dpAff[i] |= aff[j];
		}
		for (i = 1; i <= all; i++)
		{
			sub = i;
			while (sub)
			{
				sub = (sub - 1) & i;
				res = sub ^ i;
				if (dpAff[res] == all)
					dp[i] = max(dp[i], dp[sub] + 1);
			}
		}
		printf("Case %d: %d\n", ++cases, dp[all]);
	}
	return 0;
}
