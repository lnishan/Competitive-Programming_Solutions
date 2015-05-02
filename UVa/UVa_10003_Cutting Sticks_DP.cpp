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

int min_cost(const int &i1, const int &i2)
{
	int &cur = dp[i1][i2];
	if (cur != -1) return cur;
	if (i1 == i2) return cur = 0;
	int i, cost = INF;
	for (i = i1; i < i2; i++)
		cost = min(cost, min_cost(i1, i) + min_cost(i+1, i2));
	return cur = cost + d[i2+1] - d[i1];
}

int main()
{
	int i, l, n;
	while (scanf("%d", &l) == 1 && l)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		d[0] = 0;
		d[n+1] = l;
		printf("The minimum cutting is %d.\n", min_cost(0, n));
	}
	return 0;
}
