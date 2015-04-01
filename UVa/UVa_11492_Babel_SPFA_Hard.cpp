#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#define INF 0x3fffffff

using namespace std;

const int MAX_V = 4010;

map<string, int> id;
map<string, int>::iterator it;
int cnt;
struct edge { int to, wt, ch; };
vector<edge> g[MAX_V];
queue<pair<int, int> > q;
char inQ[MAX_V][30];
int dp[MAX_V][30];

inline int get_id(string &nm)
{
	it = id.find(nm);
	if (it != id.end())
		return it->second;
	else
	{
		id[nm] = cnt;
		return cnt++;
	}
}

int main()
{
	int i, j, es;
	int id_s, id_e;
	int i1, i2, c;
	int ans;
	string s1, s2, word;
	while (scanf("%d", &es) == 1 && es)
	{
		ans = INF;
		id.clear();
		cnt = 0;
		for (i = 0; i < (es << 1) + 2; i++) g[i].clear();
		while (!q.empty()) q.pop();
		
		cin >> s1 >> s2;
		id_s = get_id(s1);
		id_e = get_id(s2);
		while (es--)
		{
			cin >> s1 >> s2 >> word;
			i1 = get_id(s1);
			i2 = get_id(s2);
			const int &len = word.length();
			c = word[0] - 'a' + 1;
			g[i1].push_back( (edge){i2, len, c} );
			g[i2].push_back( (edge){i1, len, c} );
		}
		
		// init
		for (i = 0; i < cnt; i++)
			for (j = 1; j <= 26; j++)
			{
				inQ[i][j] = 0;
				dp[i][j] = INF;
			}
		
		// start
		inQ[id_s][0] = 1;
		q.push( make_pair(id_s, 0) );
		dp[id_s][0] = 0;
		while (!q.empty())
		{
			pair<int, int> &qi = q.front();
			int &vi = qi.first;
			int &chi = qi.second;
			const int &sz = g[vi].size();
			for (i = 0; i < sz; i++)
			{
				int &chj = g[vi][i].ch;
				if (chj == chi) continue;
				int &vj = g[vi][i].to;
				int &wt = g[vi][i].wt;
				if (dp[vi][chi] + wt < dp[vj][chj])
				{
					dp[vj][chj] = dp[vi][chi] + wt;
					if (!inQ[vj][chj])
					{
						inQ[vj][chj] = 1;
						q.push( make_pair(vj, chj) );
					}
				}
			}
			inQ[vi][chi] = 0;
			q.pop();
		}
		
		for (i = 1; i <= 26; i++)
			ans = min(ans, dp[id_e][i]);
		if (ans == INF)
			puts("impossivel");
		else
			printf("%d\n", ans);
	}
	return 0;
}
