#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 30;

int n, m;
map<string, int> no;
map<string, int>::iterator it1, it2;
string nm[MAX_N];
vector<int> g[MAX_N];
int t, low[MAX_N], dfn[MAX_N];
int stk[MAX_N], top;
char inStk[MAX_N];

void dfs(int vi)
{
	dfn[vi] = t++;
	low[vi] = dfn[vi];
	stk[++top] = vi;
	inStk[vi] = 1;
	int i, sz = g[vi].size();
	for (i = 0; i < sz; i++)
	{
		int &vj = g[vi][i];
		if (dfn[vj] == -1)
		{
			dfs(vj);
			low[vi] = min(low[vi], low[vj]);
		}
		else if (inStk[vj]) // in same SCC
			low[vi] = min(low[vi], dfn[vj]);
	}
	if (low[vi] == dfn[vi])
	{
		while (top > 0 && stk[top] != vi)
		{
			cout << nm[stk[top]] << ", ";
			inStk[stk[top]] = 0;
			--top;
		}
		cout << nm[stk[top]] << endl;
		inStk[stk[top]] = 0;
		--top;
	}
}

int main()
{
	int i, j, it, cases = 0;
	string s1, s2;
	int v1, v2;
	while (scanf("%d%d", &n, &m) == 2 && (n | m))
	{
		it = 0;
		no.clear();
		for (i = 0; i < n; i++) g[i].clear();
		t = 0;
		memset(dfn, -1, sizeof(dfn));
		top = -1;
		memset(inStk, 0, sizeof(inStk));
		for (i = 0; i < m; i++)
		{
			cin >> s1 >> s2;
			it1 = no.find(s1);
			if (it1 == no.end())
			{
				no[s1] = it;
				nm[it] = s1;
				v1 = it;
				it++;
			}
			else
				v1 = it1 -> second;
			it2 = no.find(s2);
			if (it2 == no.end())
			{
				no[s2] = it;
				nm[it] = s2;
				v2 = it;
				it++;
			}
			else
				v2 = it2 -> second;
			g[v1].push_back(v2);
		}
		++cases;
		if (cases > 1) puts("");
		printf("Calling circles for data set %d:\n", cases);
		for (i = 0; i < n; i++)
			if (dfn[i] == -1)
				dfs(i);
	}
	return 0;
}
