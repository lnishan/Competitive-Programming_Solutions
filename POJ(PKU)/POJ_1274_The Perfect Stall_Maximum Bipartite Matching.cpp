#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 205
#define MAX_M 205

using namespace std;

int match[MAX_N+MAX_M];
char vst[MAX_N+MAX_M];
vector<int> g[MAX_N+MAX_M];

bool dfs(int idx)
{
	int i;
	for (i = 0; i<g[idx].size(); i++)
	{
		int &v = g[idx][i];
		if (!vst[v])
		{
			if (match[v] >= 0)
			{
				vst[v] = 1;
				if (dfs(match[v]))
				{
					match[idx] = v;
					match[v] = idx;
					return true;
				}
			}
			else
			{
				match[idx] = v;
				match[v] = idx;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int i, j, k, n, m, mCnt, mm, ans;
	while ( scanf("%d%d", &n, &m)==2 )
	{
		// init
		for (i = 1; i <= MAX_N+m; i++)
		{
			match[i]=-1;
			g[i].clear();
		}
		ans = 0;
		
		// input
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &mCnt);
			while ( mCnt-- )
			{
				scanf("%d", &mm);
				g[i].push_back(MAX_N+mm);
				g[MAX_N+mm].push_back(i);
			}
		}
		
		// matching (dfs)
		for (i = 1; i <= n; i++)
			if (match[i] == -1)
			{
				memset(vst, 0, sizeof(vst));
				vst[i] = 1;
				if (dfs(i))
					ans++;
			}
		for (i = MAX_N+1; i <= MAX_N+m; i++)
			if (match[i] == -1)
			{
				memset(vst, 0, sizeof(vst));
				if (dfs(i))
					ans++;
			}
		
		// print
		printf("%d\n", ans);
	}
	return 0;
}
