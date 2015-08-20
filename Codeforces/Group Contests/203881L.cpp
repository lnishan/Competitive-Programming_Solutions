#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000005;

int v, e;
int s, t;
struct edge { int to, wt; };
vector<edge> g[N];
char vst[N];

bool can(int mask)
{
	fill(vst + 1, vst + 1 + v, 0);
	queue<int> q;
	vst[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		int vi = q.front(); q.pop();
		for (auto &e: g[vi])
		{
			if (vst[e.to] || (e.wt & mask)) continue;
			vst[e.to] = 1;
			q.push(e.to);
		}
	}
	return vst[t];
}

int main()
{
	int i;
	int vi, vj, wt;
	int mask = 0, ans = 0;
	scanf("%d%d", &v, &e);
	scanf("%d%d", &s, &t);
	for (i = 0; i < e; i++)
	{
		scanf("%d%d%d", &vi, &vj, &wt);
		g[vi].push_back( (edge) { vj, wt } );
		g[vj].push_back( (edge) { vi, wt } );
	}
	for (i = 30; i >= 0; i--)
		if (can(mask | (1 << i)))
			mask |= (1 << i);
		else
			ans |= (1 << i);
	printf("%d\n", ans);
	return 0;
}