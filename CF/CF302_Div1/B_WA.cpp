#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int N = 3002;

int v, e;
vector<int> g[N];
int df1[N], bf1[N];
int dt1[N], bt1[N];
int df2[N], bf2[N];
int dt2[N], bt2[N];
char upd[N][N];
vector<pair<int, int> > ae;
char upd2[N][N];
vector<pair<int, int> > ae2;

void get_dist(int st, int d[], int b[])
{
	int i;
	queue<int> q;
	fill(d + 1, d + 1 + v, -1);
	d[st] = 0;
	q.push(st);
	while (!q.empty())
	{
		int qi = q.front();
		q.pop();
		for (i = 0; i < g[qi].size(); i++)
		{
			int &vj = g[qi][i];
			if (d[vj] == -1)
			{
				d[vj] = d[qi] + 1;
				b[vj] = qi;
				q.push(vj);
			}
		}
	}
}

int update(int st, int ed, int b[], char upd[N][N])
{
	if (st == ed) return 0;
	int vi = st, ret = 0;
	while (vi != ed)
	{
		if (upd[b[vi]][vi])
			ret++;
		else
		{
			ae.push_back(make_pair(b[vi], vi));
			upd[b[vi]][vi] = upd[vi][b[vi]] = 1;
		}
		vi = b[vi];
	}
	return ret;
}

int main()
{
	int i, j;
	int vi, vj;
	int f1, t1, l1;
	int f2, t2, l2;
	int ans, tmp;
	int il1, il2;
	char flag;
	memset(upd, 0, sizeof(upd));
	scanf("%d%d", &v, &e);
	for (i = 0; i < e; i++)
	{
		scanf("%d%d", &vi, &vj);
		g[vi].push_back(vj);
		g[vj].push_back(vi);
	}
	scanf("%d%d%d", &f1, &t1, &l1);
	scanf("%d%d%d", &f2, &t2, &l2);
	get_dist(f1, df1, bf1);
	get_dist(t1, dt1, bt1);
	get_dist(f2, df2, bf2);
	get_dist(t2, dt2, bt2);
	if (df1[t1] > l1 || df2[t2] > l2)
		puts("-1");
	else
	{
		// check intersection
		flag = 0;
		vi = t1; while (vi != f1) { if (vi == f2 || vi == t2) { flag = 1; break; } vi = bf1[vi]; }
		vi = t2; while (vi != f2) { if (vi == f1 || vi == t1) { flag = 1; break; } vi = bf2[vi]; }
		ans = flag ? 1e9 : df1[t1] + df2[t2];
		for (i = 1; i <= v; i++)
		{
			if (df1[i] == -1 || dt1[i] == -1 || df2[i] == -1 || dt2[i] == -1) continue;
			// check l1, l2
			il1 = df1[i] + dt1[i];
			ae2.clear();
			update(i, f1, bf1, upd2);
			il1 -= update(i, t1, bt1, upd2);
			for (j = 0; j < ae2.size(); j++) { int &vi = ae2[j].first; int vj = ae2[j].second; upd2[vi][vj] = upd2[vj][vi] = 0; }
			if (il1 > l1) continue;
			
			il2 = df2[i] + dt2[i];
			ae2.clear();
			update(i, f2, bf2, upd2);
			il2 -= update(i, t1, bt1, upd2);
			for (j = 0; j < ae2.size(); j++) { int &vi = ae2[j].first; int vj = ae2[j].second; upd2[vi][vj] = upd2[vj][vi] = 0; }
			if (il2 > l2) continue;
			
			// check intersection
			tmp = df1[i] + dt1[i] + df2[i] + dt2[i];
			ae.clear();
			tmp -= update(i, f1, bf1, upd);
			tmp -= update(i, t1, bt1, upd);
			tmp -= update(i, f2, bf2, upd);
			tmp -= update(i, t2, bt2, upd);
			
			// garbage collection
			for (j = 0; j < ae.size(); j++)
			{
				int &vi = ae[j].first;
				int &vj = ae[j].second;
				upd[vi][vj] = upd[vj][vi] = 0;
			}
			if (tmp < ans) ans = tmp;
		}
		printf("%d\n", e - ans);
	}
	return 0;
}