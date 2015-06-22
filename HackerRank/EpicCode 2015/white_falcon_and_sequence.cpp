#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1LL << 62;
ll a[3002];
ll dp[3002][3002];
ll sum[3002][3002];

void get(int l, int r)
{
	if (dp[l][r] != -INF) return ;
	if (r - l <= 2)
	{
		dp[l][r] = min(0LL, a[l] * a[r]);
		sum[l][r] = a[l] * a[r];
		return ;
	}
	get(l + 1, r - 1);
	sum[l][r] = sum[l + 1][r - 1] + a[l] * a[r];
	dp[l][r] = min(dp[l + 1][r - 1], sum[l][r]);
} 

int main()
{
	int i, j, n;
	ll ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) dp[i][j] = -INF;
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			get(i, j);
			ans = max(ans, sum[i][j] - dp[i][j]);
		}
	printf("%lld\n", ans);
	return 0;
}
