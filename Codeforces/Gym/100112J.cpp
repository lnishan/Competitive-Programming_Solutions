#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1002;
const int C = 102;

int dp[N][C];
vector<int> g[N];
vector<int> z;
int cap[N];
int need[N];
int par[N];

void dfs(int vi)
{
	int i, j;
	for (auto &vj: g[vi])
		dfs(vj);
	for (i = cap[vi]; i >= need[vi]; i--)
		dp[vi][i] = max(dp[vi][i], dp[vi][i - need[vi]] + 1);
	for (i = cap[par[vi]]; i >= 0; i--)
		for (j = 0; j <= i; j++)
			dp[par[vi]][i] = max(dp[par[vi]][i], dp[par[vi]][i - j] + dp[vi][j]);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
	int i, n;
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> par[i] >> need[i] >> cap[i];
		g[par[i]].push_back(i);
		if (par[i] == 0) z.push_back(i);
	}
	cap[0] = 100;
	dfs(0);
	for (auto &vi: z)
		ans += dp[vi][cap[vi]];
	cout << ans;
	return 0;
}
