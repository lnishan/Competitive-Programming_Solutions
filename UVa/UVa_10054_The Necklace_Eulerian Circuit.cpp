#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int V = 52;

int g[V][V];
int deg[V];
int v;

void dfs(int vi)
{
	int vj;
	for (vj = 1; vj <= v; vj++)
		if (g[vi][vj])
		{
			g[vi][vj]--; g[vj][vi]--;
			dfs(vj);
			printf("%d %d\n", vj, vi);
		}
}

int main()
{
	int i, j, t, e;
	int v1, v2;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		v = 0;
		memset(g, 0, sizeof(g));
		memset(deg, 0, sizeof(deg));
		
		scanf("%d", &e);
		while (e--)
		{
			scanf("%d%d", &v1, &v2);
			v = max(v, v1); v = max(v, v2);
			g[v1][v2]++; g[v2][v1]++;
			deg[v1]++; deg[v2]++;
		}
		if (c-1) puts("");
		printf("Case #%d\n", c);
		for (i = 1; i <= v; i++)
			if (deg[i] & 1)
				break;
		if (i <= v)
			puts("some beads may be lost");
		else
			for (i = 1; i <= v; i++)
				dfs(i);
	}
	return 0;
}
