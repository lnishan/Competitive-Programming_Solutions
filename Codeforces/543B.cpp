#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 3002;

int v, e;
int d[N][N];
vector<int> g[N];

void cal_d(int st)
{
	int i;
	queue<int> q;
	fill(d[st] + 1, d[st] + 1 + v, -1);
	d[st][st] = 0;
	q.push(st);
	while (!q.empty())
	{
		int vi = q.front();
		q.pop();
		for (i = 0; i < g[vi].size(); i++)
		{
			int &vj = g[vi][i];
			if (d[st][vj] == -1)
			{
				d[st][vj] = d[st][vi] + 1;
				q.push(vj);
			}
		}
	}
}

int main()
{
	int i, j;
	int s1, t1, l1;
	int s2, t2, l2;
	int vi, vj;
	int d1, d2;
	int ans;
	scanf("%d%d", &v, &e);
	for (i = 0; i < e; i++)
	{
		scanf("%d%d", &vi, &vj);
		g[vi].push_back(vj);
		g[vj].push_back(vi);
	}
	scanf("%d%d%d", &s1, &t1, &l1);
	scanf("%d%d%d", &s2, &t2, &l2);
	for (i = 1; i <= v; i++)
		cal_d(i);
//	for (i = 1; i <= v; i++)
//		for (j = 1; j <= v; j++)
//			printf("%d %d: %d\n", i, j, d[i][j]);
	if (d[s1][t1] > l1 || d[s2][t2] > l2)
		puts("-1");
	else
	{
		ans = d[s1][t1] + d[s2][t2];
		for (i = 1; i <= v; i++)
			for (j = 1; j <= v; j++)
			{
				d1 = d[s1][i] + d[i][j] + d[j][t1];
				d2 = d[s2][i] + d[i][j] + d[j][t2];
				if (d1 <= l1 && d2 <= l2)
					ans = min(ans, d1 + d2 - d[i][j]);
				
				d1 = d[t1][i] + d[i][j] + d[j][s1];
//				d2 = d[s2][i] + d[j][t2];
				if (d1 <= l1 && d2 <= l2)
					ans = min(ans, d1 + d2 - d[i][j]);
			}
		printf("%d\n", e - ans);
	}
//	while (1);
	return 0;
}