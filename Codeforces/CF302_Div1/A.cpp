#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dp[502][502];
ll a[502];

int main()
{
	ll n, m, b, mod, ans = 0;
	int i, j, k;
	dp[0][0] = 1;
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &b, &mod);
	for (i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (i = 0; i < n; i++)
		for (j = 1; j <= m; j++)
			for (k = b; k >= a[i]; k--)
			{
				dp[j][k] += dp[j - 1][k - a[i]];
				dp[j][k] %= mod;
			}
	for (i = 0; i <= b; i++)
		ans += dp[m][i], ans %= mod;
	printf("%I64d\n", ans);
	return 0;
}