#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int V = 302;
vector<int> g[V];
int lvl[V];
pair<int, int> ae[V * V];
queue<int> q;

int main()
{
	int i, j, v, e;
	int v1, v2;
	while (scanf("%d", &v) == 1 && v)
	{
		e = 0;
		memset(lvl, -1, sizeof(lvl));
		for (i = 1; i <= v; i++) g[i].clear();
		while (scanf("%d%d", &v1, &v2) == 2 && (v1 | v2))
		{
			g[v1].push_back(v2);
			g[v2].push_back(v1);
			ae[e++] = make_pair(v1, v2);
		}
		for (i = 1; i <= v; i++)
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
				break;
		puts( i == e ? "YES" : "NO" );
	}
	return 0;
}
