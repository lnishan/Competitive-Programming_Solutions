#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_N 1005
#define MAX_M 1005

using namespace std;

int match[MAX_N+MAX_M];
vector<int> g[MAX_N+MAX_M];
char vst[MAX_N+MAX_M];

bool dfs(int idx)
{
	int i;
	for (i = 0; i < g[idx].size(); i++)
	{
		int &v = g[idx][i];
		if ( !vst[v] )
		{
			if (match[v] != -1)
			{
				vst[v] = 1;
				if (dfs(v))
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
	int i, m, n, k, a, b, matchCnt;
	
	// input
	scanf("%d%d%d", &m, &n, &k);
	while (k--)
	{
		scanf("%d%d", &a, &b);
		g[a].push_back(MAX_M+b);
		g[MAX_M+b].push_back(a);
	}
	
	// init
	matchCnt=0;
	for (i = 1; i <= MAX_M+m; i++)
		match[i] = -1;
	
	// start matching
	for (i = 1; i <= m; i++)
	{
		if (match[i] == -1)
		{
			memset(vst, 0, sizeof(vst));
			vst[i] = 1;
			if (dfs(i))
				matchCnt++;
		}
	}
	for (i = MAX_M+1; i <= MAX_M+n; i++)
	{
		if (match[i] == -1)
		{
			memset(vst, 0, sizeof(vst));
			vst[i] = 1;
			if (dfs(i))
				matchCnt++;
		}
	}
	
	// Maximum Bipartite Matching + Minimum Edge Cover = Number of Vertices
	printf("%d\n", m+n - matchCnt);
	return 0;
}
