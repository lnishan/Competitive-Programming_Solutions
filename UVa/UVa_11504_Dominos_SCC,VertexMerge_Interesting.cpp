#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 100002;
vector<int> g[MAX_N];
vector<int> grev[MAX_N];
int vs, es;
int t, low[MAX_N], dfn[MAX_N];
int stk[MAX_N], top;
char inStk[MAX_N];
int f[MAX_N];
// int scc_cnt = 0;

int findF(int idx)
{
	if (f[idx] == idx) return idx;
	return f[idx] = findF(f[idx]);
}

void unionF(int idx1, int idx2)
{
	int f1 = findF(idx1), f2 = findF(idx2);
	int i, sz = grev[f2].size();
	f[f2] = f1;
	for (i = 0; i < sz; i++)
		grev[f1].push_back(grev[f2][i]);
}

void dfs(int vi)
{
	dfn[vi] = t++;
	low[vi] = dfn[vi];
	stk[++top] = vi;
	inStk[vi] = 1;
	int i, sz = g[vi].size();
	for (i = 0; i < sz; i++)
	{
		int &vj = g[vi][i];
		if (dfn[vj] == -1)
		{
			dfs(vj);
			low[vi] = min(low[vi], low[vj]);
		}
		else if (inStk[vj])
			low[vi] = min(low[vi], dfn[vj]);
	}
	if (low[vi] == dfn[vi])
	{
		// scc_cnt++;
		while (top >= 0 && stk[top] != vi) // merge scc into a vertex
		{
			unionF(vi, stk[top]);
			inStk[stk[top]] = 0;
			--top;
		}
		inStk[stk[top]] = 0;
		--top;
	}
}

int main()
{
	int i, j, tt, sz;
	int v1, v2;
	int ans, indeg;
	scanf("%d", &tt);
	while (tt--)
	{
		scanf("%d%d", &vs, &es);
		ans = 0;
		t = 0;
		memset(dfn, -1, sizeof(dfn));
		top = -1;
		memset(inStk, 0, sizeof(inStk));
		for (i = 1; i <= vs; i++)
		{
			g[i].clear();
			grev[i].clear();
			f[i] = i;
		}
		for (i = 0; i < es; i++)
		{
			scanf("%d%d", &v1, &v2);
			g[v1].push_back(v2);
			grev[v2].push_back(v1);
		}
		for (i = 1; i <= vs; i++)
			if (dfn[i] == -1)
				dfs(i);
		for (i = 1; i <= vs; i++)
			if (f[i] == i)
			{
				indeg = 0;
				sz = grev[i].size();
				for (j = 0; j < sz; j++)
					if (findF(grev[i][j]) != i)
					{
						indeg++;
						break;
					}
				if (indeg == 0) ans++;
			}
		printf("%d\n", ans);
		// printf("%d\n", scc_cnt);
	}
	return 0;
}
