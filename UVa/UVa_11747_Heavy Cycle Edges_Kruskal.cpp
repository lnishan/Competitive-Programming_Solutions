#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int V = 1002;
const int E = 25002;

int v, e;
int f[V];
struct edge
{
	int v1, v2;
	int wt;
	bool operator < (const edge &rhs)const
	{
		return wt < rhs.wt;
	}
} ae[E];
char used[E];
vector<int> ans;

int findF(int idx)
{
	if (f[idx] == idx)
		return idx;
	else
		return f[idx] = findF(f[idx]);
}

int main()
{
	int i, j, cnt;
	int f1, f2;
	while (scanf("%d%d", &v, &e) == 2 && (v | e))
	{
		cnt = 0;
		ans.clear();
		for (i = 0; i < v; i++) f[i] = i;
		memset(used, 0, sizeof(used));
		
		for (i = 0; i < e; i++)
			scanf("%d%d%d", &ae[i].v1, &ae[i].v2, &ae[i].wt);
		sort(ae, ae+e);
		for (i = 0; i < e; i++)
		{
			edge &e = ae[i];
			f1 = findF(e.v1);
			f2 = findF(e.v2);
			if (f1 != f2)
			{
				f[f2] = f1;
				cnt++;
				used[i] = 1;
			}
		}
		if (cnt == e)
			puts("forest");
		else
		{
			for (i = 0; i < e; i++)
				if (!used[i])
				{
					if (!cnt) putchar(' ');
					printf("%d", ae[i].wt);
					cnt = 0;
				}
			puts("");
		}
	}
	return 0;
}
