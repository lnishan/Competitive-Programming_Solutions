#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 100005

using namespace std;

vector<int> g[N];

int dfs(int idx, const int &per)
{
	int i, ret = 0, deg = g[idx].size(),
	need = (deg * per) % 100 == 0 ? deg * per/100 : deg * per/100 + 1;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (i = 0; i < deg; i++)
		pq.push( dfs(g[idx][i], per) );
	for (i = 0; i < need; i++)
	{
		ret += pq.top();
		pq.pop();
	}
	return max(1, ret);
}

int main()
{
	int i, n, t, boss;
	while (scanf("%d%d", &n, &t) == 2 && (n | t))
	{
		for (i = 0; i <= n; i++) g[i].clear();
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &boss);
			g[boss].push_back(i);
		}
		printf("%d\n", dfs(0, t) );
	}
	return 0;
}
