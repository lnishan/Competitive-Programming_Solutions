#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3fffffff

using namespace std;

const int V = 30;

int v, e;
vector<pair<int, int> > g[V], G[V];
int d[V], D[V];
char inQ[V];

void spfa(int st, vector<pair<int, int> > g[], int d[])
{
	int i;
	queue<int> q;
	fill(d, d+v, INF);
	fill(inQ, inQ+v, 0);
	d[st] = 0;
	inQ[st] = 1;
	q.push(st);
	while (!q.empty())
	{
		int &vi = q.front();
		const int &sz = g[vi].size();
		for (i = 0; i < sz; i++)
		{
			int &vj = g[vi][i].first;
			int &wt = g[vi][i].second;
			if (d[vi] + wt < d[vj])
			{
				d[vj] = d[vi] + wt;
				if (!inQ[vj])
				{
					inQ[vj] = 1;
					q.push(vj);
				}
			}
		}
		q.pop();
	}
}

int main()
{
	int i, j;
	char age, type, from, to; int wt;
	int vi, vj;
	int min_wt; vector<int> min_idx;
	while (scanf("%d", &e) == 1 && e)
	{
		v = 0;
		min_wt = INF;
		for (i = 0; i < V; i++)
		{
			g[i].clear();
			G[i].clear();
		}
		while (e--)
		{
			scanf(" %c %c %c %c %d", &age, &type, &from, &to, &wt);
			vi = from - 'A';
			vj = to - 'A';
			v = max(v, vi+1); v = max(v, vj+1);
			if (age == 'Y')
			{
				g[vi].push_back(make_pair(vj, wt));
				if (type == 'B')
					g[vj].push_back(make_pair(vi, wt));
			}
			else // M
			{
				G[vi].push_back(make_pair(vj, wt));
				if (type == 'B')
					G[vj].push_back(make_pair(vi, wt));
			}
		}
		scanf(" %c %c", &from, &to);
		vi = from - 'A';
		vj = to - 'A';
		spfa(vi, g, d);
		spfa(vj, G, D);
		for (i = 0; i < v; i++)
			if (d[i] != INF && D[i] != INF)
			{
				wt = d[i] + D[i];
				if (wt < min_wt)
				{
					min_wt = wt;
					min_idx.clear();
					min_idx.push_back(i);
				}
				else if (wt == min_wt)
					min_idx.push_back(i);
			}
		if (min_wt == INF)
			puts("You will never meet.");
		else
		{
			printf("%d", min_wt);
			for (i = 0; i < min_idx.size(); i++)
				printf(" %c", min_idx[i] + 'A');
			puts("");
		}
	}
	return 0;
}
