#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int V = 105;

int v, e;
int l[V], top;
vector<int> g[V];
char used[V];

void dfs(int vi)
{
	int i;
	used[vi] = 1;
	const int &sz = g[vi].size();
	for (i = 0; i < sz; i++)
	{
		int &vj = g[vi][i];
		if (!used[vj])
			dfs(vj);
	}
	l[++top] = vi;
}

int main()
{
	int i, j;
	int v1, v2;
	while (scanf("%d%d", &v, &e) == 2 && (v | e))
	{
		memset(used, 0, sizeof(used));
		for (i = 1; i <= v; i++) g[i].clear();
		top = 0;
		for (i = 0; i < e; i++)
		{
			scanf("%d%d", &v1, &v2);
			g[v1].push_back(v2);
		}
		for (i = 1; i <= v; i++)
			if (!used[i])
				dfs(i);
		for (i = top; i >= 1; i--)
		{
			printf("%d", l[i]);
			if (i > 1) putchar(' ');
		}
		puts("");
	}
	return 0;
}
