#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
#define MAX_V 205
#define SRC 0
#define SINK MAX_V - 1
#define OUT(X) 101 + X

using namespace std;

vector<int> g[MAX_V];
int r[MAX_V][MAX_V];
int lvl[MAX_V];
queue<int> q;

int iter[MAX_V];

void addEdge(int s, int e, int c)
{
	r[s][e] += c;
	// r[e][c] += 0;
	g[s].push_back(e);
	g[e].push_back(s);
}

void doFlow(int s, int e, int f)
{
	r[s][e] -= f;
	r[e][s] += f;
}

int bfs(const int &s, const int &e)
{
	int i, sz, qi;
	while (!q.empty()) q.pop();
	memset(lvl, -1, sizeof(lvl));
	lvl[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		qi = q.front();
		sz = g[qi].size();
		for (i = 0; i < sz; i++)
		{
			int &qj = g[qi][i];
			if (r[qi][qj] > 0 && lvl[qj] < 0)
			{
				lvl[qj] = lvl[qi]+1;
				q.push(qj);
			}
		}
		q.pop();
	}
	return lvl[e];
}

int dfs(int idx, int minF, const int &dest)
{
	if (idx == dest) return minF;
	int sz = g[idx].size(), ret;
	for (int &i = iter[idx]; i < sz; i++)
	{
		int &idxJ = g[idx][i];
		if (r[idx][idxJ] > 0 && lvl[idx] < lvl[idxJ])
		{
			ret = dfs(idxJ, min(minF, r[idx][idxJ]), dest);
			if (ret > 0)
			{
				doFlow(idx, idxJ, ret);
				return ret;
			}
		}
	}
	return 0;
}

int maxFlow(const int &s, const int &e)
{
	int ret = 0, f;
	while (bfs(s, e) >= 0)
	{
		memset(iter, 0, sizeof(iter));
		while ( (f = dfs(s, INF, e)) > 0 )
			ret += f;
	}
	return ret;
}

int main()
{
	int i, j, vs, vcap, es, s, e, c, css, ces, v;
	while (scanf("%d", &vs) == 1)
	{
		memset(r, 0, sizeof(r));
		for (i = 0; i < MAX_V; i++) g[i].clear();
		
		// *** Split vertice. Vertice-capacity transformed to Link-capacity
		for (i = 1; i <= vs; i++)
		{
			scanf("%d", &vcap);
			addEdge(i, OUT(i), vcap);
		}
		
		scanf("%d", &es);
		while (es--)
		{
			scanf("%d%d%d", &s, &e, &c);
			addEdge(OUT(s), e, c);
		}
		
		scanf("%d%d", &css, &ces);
		while (css--)
		{
			scanf("%d", &v);
			addEdge(SRC, v, INF);
		}
		while (ces--)
		{
			scanf("%d", &v);
			addEdge(OUT(v), SINK, INF);
		}
		
		printf("%d\n", maxFlow(SRC, SINK));
	}
	return 0;
}
