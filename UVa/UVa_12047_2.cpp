#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define INF 0x3fffffff

using namespace std;

const int V = 10005;
const int E = 100005;

int vs, es;
struct edge_full { int from, to, wt; } ae[E];
struct edge { int to, wt; };
vector<edge> g_f[V];
vector<edge> g_r[V];
int d_f[V], d_r[V];
char used[V];

struct vert
{
	int idx;
	int wt;
	bool operator < (const vert &rhs)const
	{
		return wt > rhs.wt;
	}
};
priority_queue<vert> pq;

void dijkstra(const int &st, vector<edge> (&g)[V], int (&d)[V])
{
	int i, j, nw;
	memset(used, 0, sizeof(used));
	while (!pq.empty()) pq.pop();
	for (i = 1; i <= vs; i++) d[i] = INF;
	
	d[st] = 0;
	pq.push( (vert){st, 0} );
	for (i = 1; i < vs; i++)
	{
		while (!pq.empty() && used[pq.top().idx]) pq.pop();
		if (pq.empty()) break;
		int qi = pq.top().idx;
		const int &sz = g[qi].size();
		used[qi] = true;
		for (j = 0; j < sz; j++)
		{
			edge &e = g[qi][j];
			int &qj = e.to;
			int &wt = e.wt;
			if (!used[qj] && (nw = d[qi] + wt) < d[qj])
			{
				d[qj] = nw;
				pq.push( (vert){qj, nw} );
			}
		}
		pq.pop();
	}
}

int main()
{
	int i, j, t, st, ed, p;
	int v1, v2, wt;
	int ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d", &vs, &es, &st, &ed, &p);
		ans = -1;
		for (i = 1; i <= vs; i++)
		{
			g_f[i].clear();
			g_r[i].clear();
		}
		for (i = 0; i < es; i++)
		{
			scanf("%d%d%d", &v1, &v2, &wt);
			g_f[v1].push_back( (edge){v2, wt} );
			g_r[v2].push_back( (edge){v1, wt} );
			ae[i] = (edge_full){v1, v2, wt};
		}
		dijkstra(st, g_f, d_f);
		dijkstra(ed, g_r, d_r);
		
		for (i = 0; i < es; i++)
		{
			int &v1 = ae[i].from;
			int &v2 = ae[i].to;
			int &wt = ae[i].wt;
			if (d_f[v1] == INF || d_r[v2] == INF) continue;
			if (d_f[v1] + wt + d_r[v2] <= p)
				ans = max(ans, wt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
