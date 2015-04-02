/* The answer is the total number of nodes on the smaller side
 * Note that when a node is isolated (no nodes on the other side), we still need to add 1 to the answer
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

const int V = 202;
const int E = 10002;

int v, e;
vector<int> g[V];
char vst[V];

// for bipartite graph check
pair<int, int> ae[E];
int lvl[V];
queue<int> q;

void bicolor(int vi, int c, int (&cnt)[2])
{
	int i;
	const int &sz = g[vi].size();
	vst[vi] = 1;
	for (i = 0; i < sz; i++)
	{
		int &vj = g[vi][i];
		if (!vst[vj])
			bicolor(vj, c^1, cnt);
	}
	cnt[c]++;
}

bool bipartite()
{
	int i;
	for (i = 0; i < v; i++)
		if (lvl[i] == -1)
		{
			while (!q.empty()) q.pop();
			lvl[i] = 0;
			q.push(i);
			while (!q.empty())
			{
				int &qi = q.front();
				const int &sz = g[qi].size();
				for (i = 0; i < sz; i++)
				{
					int &qj = g[qi][i];
					if (lvl[qj] == -1)
					{
						lvl[qj] = lvl[qi] + 1;
						q.push(qj);
					}
				}
				q.pop();
			}
		}
	for (i = 0; i < e; i++)
		if (lvl[ae[i].first] % 2 == lvl[ae[i].second] % 2)
			return false;
	return true;
}

int main()
{
	int i, t;
	int v1, v2;
	int ans;
	int cnt[2];
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%d%d", &v, &e);
		for (i = 0; i < v; i++)
		{
			g[i].clear();
			vst[i] = 0;
			lvl[i] = -1;
		}
		while (!q.empty()) q.pop();
		
		for (i = 0; i < e; i++)
		{
			scanf("%d%d", &v1, &v2);
			g[v1].push_back(v2);
			g[v2].push_back(v1);
			ae[i] = make_pair(v1, v2);
		}
		if (bipartite())
		{
			for (i = 0; i < v; i++)
				if (!vst[i])
				{
					cnt[0] = cnt[1] = 0;
					bicolor(i, 0, cnt);
					if (cnt[1] == 0)
						ans++;
					else
						ans += min(cnt[0], cnt[1]);
				}
			printf("%d\n", ans);
		}
		else
			puts("-1");
	}
	return 0;
}
