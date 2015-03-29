#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 102;

int vs;
vector<int> g[MAX_V];
int t, low[MAX_V], dfn[MAX_V];
vector<pair<int, int> > ansE;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

inline void pushAns(const int &vi, const int &vj)
{
	if (vi < vj)
		ansE.push_back(make_pair(vi, vj));
	else
		ansE.push_back(make_pair(vj, vi));
}
int dfs(int p, int vi) // returns low
{
	dfn[vi] = t++;
	low[vi] = dfn[vi];
	int i, sz = g[vi].size(), l;
	for (i = 0; i < sz; i++)
	{
		int &vj = g[vi][i];
		if (dfn[vj] == -1)
		{
			l = dfs(vi, vj);
			low[vi] = min(low[vi], l);
			if (l > dfn[vi])
				pushAns(vi, vj);
		}
		else if (vj != p)
			low[vi] = min(low[vi], dfn[vj]);
	}
	return low[vi];
}

int main()
{
	int i, j, k, es, vi, vj;
	while (scanf("%d", &vs) == 1)
	{
		ansE.clear();
		t = 0;
		for (i = 0; i < vs; i++)
		{
			g[i].clear();
			dfn[i] = -1;
			scanf("%d", &vi);
			scanf(" (%d)", &es);
			for (j = 0; j < es; j++)
			{
				scanf("%d", &vj);
				g[vi].push_back(vj);
			}
		}
		for (i = 0; i < vs; i++)
			if (dfn[i] == -1)
				dfs(-1, i);
		
		printf("%d critical links\n", ansE.size());
		sort(ansE.begin(), ansE.end(), cmp);
		for (i = 0; i < ansE.size(); i++)
			printf("%d - %d\n", ansE[i].first, ansE[i].second);
		puts("");
	}
	return 0;
}

