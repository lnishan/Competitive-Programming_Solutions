#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3fffffff
#define OUT(X) v + X

using namespace std;

const int V = 110;

struct edge { int to, res, rev; };
vector<edge> g[V];
int lvl[V];
queue<int> q;
int iter[V];

void addEdge(const int &from, const int &to, const int &fcap, const int &bcap)
{
	g[from].push_back( (edge){to, fcap, g[to].size()} );
	g[to].push_back( (edge){from, bcap, g[from].size()-1} );
}

int dfs(const int &vi, const int &sink, const int &minF)
{
	if (vi == sink) return minF;
	int ret;
	const int &sz = g[vi].size();
	for (int &i = iter[vi]; i < sz; i++)
	{
		edge &e = g[vi][i];
		if (e.res > 0 && lvl[vi] < lvl[e.to])
		{
			ret = dfs(e.to, sink, min(minF, e.res));
			if (ret > 0)
			{
				e.res -= ret;
				g[e.to][e.rev].res += ret;
				return ret;
			}
		}
	}
	return 0;
}

int bfs(const int &src, const int &sink)
{
	int i;
	memset(lvl, -1, sizeof(lvl));
	while (!q.empty()) q.pop();
	lvl[src] = 0;
	q.push(src);
	while (!q.empty())
	{
		int &qi = q.front();
		const int &sz = g[qi].size();
		for (i = 0; i < sz; i++)
		{
			edge &e = g[qi][i];
			if (e.res > 0 && lvl[e.to] == -1)
			{
				lvl[e.to] = lvl[qi] + 1;
				q.push(e.to);
			}
		}
		q.pop();
	}
	return lvl[sink];
}

int max_flow(const int &src, const int &sink)
{
	int f = 0, ret;
	while (bfs(src, sink) != -1)
	{
		memset(iter, 0, sizeof(iter));
		while ( (ret = dfs(src, sink, INF)) > 0 )
			f += ret;
	}
	return f;
}

int main()
{
	int i, c = 0, v, e, src, sink;
	int v1, v2, cap;
	while (scanf("%d%d", &v, &e) == 2 && (v | e))
	{
		for (i = 1; i <= (v << 1); i++) g[i].clear();
		src = 1; sink = v;
		for (i = 0; i < v-2; i++)
		{
			scanf("%d%d", &v1, &cap);
			addEdge(v1, OUT(v1), cap, 0);
		}
		while (e--)
		{
			scanf("%d%d%d", &v1, &v2, &cap);
			bool ret1 = (v1 == 1 || v1 == v);
			bool ret2 = (v2 == 1 || v2 == v);
			if (ret1 && ret2)
				addEdge(v1, v2, cap, cap);
			else if (ret1) 
			{
				addEdge(v1, v2, cap, 0);
				addEdge(OUT(v2), v1, cap, 0);
			}
			else if (ret2)
			{
				addEdge(v2, v1, cap, 0);
				addEdge(OUT(v1), v2, cap, 0);
			}
			else
			{
				addEdge(OUT(v1), v2, cap, 0);
				addEdge(OUT(v2), v1, cap, 0);
			}
		}
		printf("%d\n", max_flow(src, sink));
	}
	return 0;
}
