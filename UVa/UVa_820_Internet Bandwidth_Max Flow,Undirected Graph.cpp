#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_V 102
#define INF 2147483647

using namespace std;

int r[MAX_V][MAX_V];
vector<int> g[MAX_V];

queue<int> q;
char vst[MAX_V];
int lvl[MAX_V];

int iter[MAX_V];

void addEdge(int s, int e, int c)
{
	r[s][e] += c;
	g[s].push_back(e);
}

void doFlow(int s, int e, int f)
{
	r[s][e] -= f;
	r[e][s] += f;
}

int bfs(const int &s, const int &e)
{
	int i, qi, sz;
	memset(vst,  0, sizeof(vst));
	memset(lvl, -1, sizeof(lvl));
	vst[s] = 1;
	lvl[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		qi = q.front();
		sz = g[qi].size();
		for (i = 0; i < sz; i++)
		{
			int &qj = g[qi][i];
			if (r[qi][qj] > 0 && !vst[qj])
			{
				vst[qj] = 1;
				lvl[qj] = lvl[qi] + 1;
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
	int ret, sz = g[idx].size();
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
	int i, j, cases = 0, vs, s, e, c, v1, v2, cap;
	while (scanf("%d", &vs) == 1 && vs > 0)
	{
		memset(r, 0, sizeof(r));
		for (i = 1; i <= vs; i++) g[i].clear();
		scanf("%d%d%d", &s, &e, &c);
		while (c--)
		{
			scanf("%d%d%d", &v1, &v2, &cap);
			addEdge(v1, v2, cap);
			addEdge(v2, v1, cap);
		}
		printf("Network %d\n", ++cases);
		printf("The bandwidth is %d.\n\n", maxFlow(s, e));
	}
	return 0;
}
