#include <bits/stdc++.h>

using namespace std;

const int N = 202;
const int K = 1002;
const int MOD = 1e9 + 7;

int a[N];
long long dp[2][N][K];

int main() {
	int i, j, k, f, n, m;
	f = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	dp[0][0][0] = dp[0][1][0] = 1;
	for (i = 1; i < n; i++, f^=1) {
		for (j = 0; j <= i + 1; j++) for (k = 0; k < K; k++) dp[f^1][j][k] = 0;
		// printf("-%d\n", i);
		for (j = 0; j <= i; j++)
			for (k = 0; k < K; k++)
				if (dp[f][j][k]) {
					int nm = k + (a[i] - a[i - 1]) * j;
					if (nm < K) {
						// printf("dp[%d][%d] = %d => dp[%d][%d] dp[%d][%d] dp[%d][%d]\n", j, k, dp[f][j][k], j + 1, nm, j, nm, j - 1, nm);
						dp[f^1][j + 1][nm] = (dp[f^1][j + 1][nm] + dp[f][j][k]) % MOD;
						dp[f^1][j][nm] = (dp[f^1][j][nm] + dp[f][j][k] * (j + 1)) % MOD;
						if (j) dp[f^1][j - 1][nm] = (dp[f^1][j - 1][nm] + dp[f][j][k] * j) % MOD;
					}
				}
	}
	int ans = 0;
	for (k = 0; k <= m; k++)
		ans = (ans + dp[f][0][k]) % MOD;
	printf("%d\n", ans);
	return 0;
}
