#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1005;
const int inf = 1e9;
int dp[N];
queue<int> q;
vector<int> g[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, n, h, l;
	int hi, vi, vj, maxh = 0;
	cin >> n >> h >> l;
	fill(dp, dp + n, inf);
	for (i = 0; i < h; i++)
	{
		cin >> hi;
		dp[hi] = 0;
		q.push(hi);
	}
	for (i = 0; i < l; i++)
	{
		cin >> vi >> vj;
		g[vi].push_back(vj);
		g[vj].push_back(vi);
	}
	while (!q.empty())
	{
		int vi = q.front(); q.pop();
		for (auto &vj: g[vi])
		{
			if (dp[vi] + 1 < dp[vj])
			{
				dp[vj] = dp[vi] + 1;
				q.push(vj);
			}
		}
	}
	for (i = 0; i < n; i++)
		if (dp[i] > maxh)
		{
			maxh = dp[i];
			hi = i;
		}
	cout << hi;
	return 0;
}
