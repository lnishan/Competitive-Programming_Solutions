#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 2005;
const int MOD = 1e9 + 7;

int dp[M][M]; // length prefix sum
char s[(int)1e5 + 5];

int main() {
	int i, j;
	dp[0][0] = 1;
	for (i = 0; i < M - 1; i++) {
		for (j = 0; j <= i; j++) {
			if (j + 1 < M) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
			if (j - 1 >= 0) dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
		}
	}
	int n, m;
	scanf("%d%d", &n, &m);
	scanf(" "); gets(s);
	int pre = 0, min_pre = 1e9;
	for (i = 0; i < m; min_pre = min(min_pre, pre), i++)
		pre += s[i] == '(' ? 1 : -1;
	if (n - m < -min_pre || pre > n - m) {
		puts("0");
		return 0;
	}
	int lb = max(0, -min_pre), ans = 0;
	for (i = lb; i <= n - m; i++) { // pre length
		for (j = lb; j <= i; j++) {
			if (j + pre > n - m - i) break;
			ans += ((ll)dp[i][j] * dp[n - m - i][j + pre]) % MOD;
			ans %= MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}
