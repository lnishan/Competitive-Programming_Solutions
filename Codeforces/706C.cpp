#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
const int L = 1e5 + 2;
const ll inf = 1e18;

void rev(char *s_rev, const char *s) {
	int i, l = strlen(s);
	for (i = 0; i < l; ++i)
		s_rev[i] = s[l - i - 1];
	s_rev[l] = 0;
}

ll cost[N], dp[N][2];
char prv_s[L], 
	 prv_s_rev[L], 
	 s[L], 
	 s_rev[L];

int main() {
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%I64d", &cost[i]);
	scanf(" ");
	gets(prv_s);
	rev(prv_s_rev, prv_s);
	dp[0][0] = 0;
	dp[0][1] = cost[0];
	for (i = 1; i < n; ++i) {
		gets(s);
		rev(s_rev, s);
		dp[i][0] = dp[i][1] = inf;

		if (strcmp(prv_s, s) <= 0)
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (strcmp(prv_s_rev, s) <= 0)
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);

		if (strcmp(prv_s, s_rev) <= 0)
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
		if (strcmp(prv_s_rev, s_rev) <= 0)
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);

		strcpy(prv_s, s);
		strcpy(prv_s_rev, s_rev);
	}
	ll ans = min(dp[n - 1][0], dp[n - 1][1]);
	if (ans == inf)
		puts("-1");
	else
		printf("%I64d\n", ans);
	return 0;
}
