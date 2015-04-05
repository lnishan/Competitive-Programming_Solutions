#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 202;

int deg[N];
vector<int> g[N];
char vst[N];

void dfs(int vi)
{
	vst[vi] = 1;
	int i;
	const int &sz = g[vi].size();
	for (i = 0; i < sz; i++)
	{
		int &vj = g[vi][i];
		if (!vst[vj])
			dfs(vj);
	}
}

int main()
{
	int i, v, e;
	int v1, v2;
	int cnt;
	while (scanf("%d%d", &v, &e) == 2)
	{
		memset(deg, 0, sizeof(deg));
		for (i = 0; i < v; i++) g[i].clear();
		for (i = 0; i < e; i++)
		{
			scanf("%d%d", &v1, &v2);
			deg[v2]++;
			deg[v1]++;
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		for (i = 0; i < v; i++)
			if (deg[i] & 1)
				break;
		if (i < v)
			puts("Not Possible");
		else
		{
			if (e == 0)
				puts("Not Possible");
			else
			{
				cnt = 0;
				memset(vst, 0, sizeof(vst));
				for (i = 0; i < v && cnt < 2; i++)
					if (!vst[i] && deg[i] > 0)
					{
						dfs(i);
						cnt++;
					}
				if (cnt > 1)
					puts("Not Possible");
				else
					puts("Possible");
			}
		}
	}
	return 0;
}
