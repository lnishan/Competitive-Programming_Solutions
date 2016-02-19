#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
typedef long long ll;

vector<int> g[N];
char vst[N];
int dp[N][3];

void dfs(int vi) {
	int child_cnt = 0;
	vst[vi] = 1;
	int mx[2] = {(int)-1e9, (int)-1e9};
	dp[vi][0] = 0;
	for (auto &vj: g[vi]) {
		if (vst[vj]) continue;
		child_cnt++;
		dfs(vj);
		int disc = max(max(dp[vj][0], dp[vj][1]), dp[vj][2]);
		dp[vi][0] += disc;
		int tmp = max(dp[vj][0], dp[vj][1]) - disc;
		if (tmp >= mx[0]) {
			mx[1] = mx[0];
			mx[0] = tmp;
		} else if (tmp >= mx[1])
			mx[1] = tmp;
	}
	
	if (child_cnt < 2)
		dp[vi][2] = 0;
	else
		dp[vi][2] = dp[vi][0] + mx[0] + mx[1] + 2;
	
	if (child_cnt < 1)
		dp[vi][1] = 0;
	else
		dp[vi][1] = dp[vi][0] + mx[0] + 1;
}

int main() {
	int i, j, tt, n, x, y;
	int vi, vj;
	scanf("%d%d%d", &n, &x, &y);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &vi, &vj);
		g[vi].push_back(vj);
		g[vj].push_back(vi);
	}
	if (x < y) {
		dfs(1);
		// printf("%d\n", max(max(dp[1][0], dp[1][1]), dp[1][2]));
		int edges = max(max(dp[1][0], dp[1][1]), dp[1][2]);
		printf("%I64d\n", (ll)x * edges + (ll)y * (n - 1 - edges));
	} else {
		for (i = 1; i <= n; i++)
			if (g[i].size() == n - 1) break;
		if (i <= n)
			printf("%I64d\n", (ll)y * (n - 2) + (ll)x);
		else
			printf("%I64d\n", (ll)y * (n - 1));
	}
	return 0;
}
