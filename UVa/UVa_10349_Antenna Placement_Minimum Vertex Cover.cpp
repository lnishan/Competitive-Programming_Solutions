#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define C(X,Y) ((X)*w + (Y))

using namespace std;

const int W = 12;
const int H = 42;
const int N = 402;

int match[N];
char vst[N];
vector<int> g[N];
char m[H][W];

bool dfs(int vi)
{
	int i;
	vst[vi] = 1;
	for (i = 0; i < g[vi].size(); i++)
	{
		int &vj = g[vi][i];
		if (match[vj] == -1) { match[vi] = vj; match[vj] = vi; return true; }
		if (vst[match[vj]]) continue;
		if (dfs(match[vj]))
		{
			match[vi] = vj;
			match[vj] = vi;
			return true;
		}
	}
	return false;
}

void add_edge(const int &vi, const int &vj)
{
	g[vi].push_back(vj);
	g[vj].push_back(vi);
}

int main()
{
	char s[W+1];
	int i, j, k, t, h, w, ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d ", &h, &w);
		
		ans = 0;
		memset(match, -1, sizeof(match));
		for (i = 0; i < h*w; i++) g[i].clear();
		
		for (i = 0; i < h; i++)
		{
			fgets(s, W+1, stdin);
			for (j = 0; j < w; j++)
				m[i][j] = s[j] == '*';
		}
		
		
		// horizontal
		for (i = 0; i < h; i++)
			for (j = 1; j < w; j++)
				if (m[i][j] && m[i][j-1])
					add_edge( C(i, j-1), C(i, j) );
		// vertical
		for (j = 0; j < w; j++)
			for (i = 1; i < h; i++)
				if (m[i][j] && m[i-1][j])
					add_edge( C(i-1, j), C(i, j) );
		
		
		/*for (i = 0; i < h*w; i++)
			for (j = 0; j < g[i].size(); j++)
				printf("(%d, %d) === (%d, %d)\n", i / w, i % w, g[i][j] / w, g[i][j] % w);*/
		
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (m[i][j] && match[ C(i, j) ] == -1)
				{
					memset(vst, 0, sizeof(vst));
					if (dfs( C(i, j) ))
						ans++;
				}
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (m[i][j] && match[ C(i, j) ] == -1)
					ans++;
		printf("%d\n", ans);
	}
	return 0;
}
