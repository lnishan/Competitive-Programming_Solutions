#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 102

using namespace std;

int n, m;
int s1[N], s2[N];
int ps1, ps2;
int top1, top2;
char g[N][N];

int cntPairs(int idx, int stk[], const int &top)
{
	int i, ret = 0;
	for (i = 1; i <= top; i++)
		if (g[idx][stk[i]])
			ret++;
	return ret;
}

int main()
{
	int i, t, vi, vj, c1, c2, minTop;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		top1 = top2 = 0;
		ps1 = ps2 = 0;
		memset(g, 0, sizeof(g));
		scanf("%d%d", &n, &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &vi, &vj);
			g[vi][vj] = g[vj][vi] = 1;
		}
		for (i = 1; i <= n; i++)
		{
			c1 = cntPairs(i, s1, top1);
			c2 = cntPairs(i, s2, top2);
			if (c1 < c2)
			{
				s1[++top1] = i;
				ps1 += c1;
			}
			else
			{
				s2[++top2] = i;
				ps2 += c2;
			}
		}
		
		printf("Case #%d: ", c);
		if (ps1 > (m >> 1) || ps2 > (m >> 1))
			printf("Impossible\n\n");
		else
		{
			minTop = min(top1, top2);
			printf("%d\n", minTop);
			for (i = 1; i <= minTop; i++)
			{
				if (i > 1) putchar(' ');
				printf("%d", s1[i]);
			}
			puts("");
		}
	}
	return 0
	;
}
