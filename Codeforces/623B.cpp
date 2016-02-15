#include <bits/stdc++.h>
#define LLL "%I64d"

using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int P = 35000;
const ll inf = 1e18;

int n, arr[N];
ll a, b;
ll dp[N][3]; // 0 = not started, 1 = started, 2 = finished

int plist[P >> 1], pcnt;
char isp[P];

void sieve() {
	int i, j;
	pcnt = 0;
	fill(isp, isp + P, 1);
	for (i = 2; i < 101; i++)
		if (isp[i])
			for (j = i * i; j < P; j += i)
				isp[j] = 0;
	for (i = 2; i < P; i++)
		if (isp[i])
			plist[pcnt++] = i;
	// printf("%d\n", pcnt);
}

ll get_min(int p, int l, int r) {
	int i;
	dp[l - 1][0] = 0;
	dp[l - 1][1] = dp[l - 1][2] = inf;
	for (i = l; i <= r; i++) {
		if (arr[i] % p == 0) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + a;
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]);
		} else if ((arr[i] - 1) % p == 0 || (arr[i] + 1) % p == 0) {
			dp[i][0] = dp[i - 1][0] + b;
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a;
			dp[i][2] = min(dp[i - 1][1] + a, dp[i - 1][2] + b);
		} else {
			dp[i][0] = inf;
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + a;
			dp[i][2] = dp[i - 1][1] + a;
		}
		// printf("%d: %I64d, %I64d, %I64d\n", i, dp[i][0], dp[i][1], dp[i][2]);
	}
	return min(min(dp[r][0], dp[r][1]), dp[r][2]);
}

ll get_ans(int ai, int ql, int qr) {
	int i;
	ll ret = inf;
	for (i = 0; i < pcnt && plist[i] * plist[i] <= ai; i++)
		if (ai % plist[i] == 0) {
			ret = min(ret, get_min(plist[i], ql, qr));
			while (ai % plist[i] == 0) ai /= plist[i];
		}
	if (ai > 1) ret = min(ret, get_min(ai, ql, qr));
	return ret;
}

int main() {
	int i;
	sieve();
	scanf("%d", &n);
	scanf(LLL, &a); scanf(LLL, &b);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	ll ans = min(get_ans(arr[1], 2, n), get_ans(arr[n], 1, n - 1));
	ans = min(ans, get_ans(arr[1] - 1, 2, n) + b);
	ans = min(ans, get_ans(arr[1] + 1, 2, n) + b);
	ans = min(ans, get_ans(arr[n] - 1, 1, n - 1) + b);
	ans = min(ans, get_ans(arr[n] + 1, 1, n - 1) + b);
	printf(LLL, ans);
	return 0;
}
