#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000005;

int a[N];
int dp[N];

int main()
{
	int i, j, n;
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	for (i = 0; i < n; dp[a[i]] = 1, i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		for (j = a[i] * 2; j <= a[n - 1]; j += a[i])
			if (dp[j])
				dp[j] = max(dp[j], dp[a[i]] + 1);
	for (i = 0; i < n; i++)
		ans = max(ans, dp[a[i]]);
	printf("%d\n", ans);
	return 0;
}
