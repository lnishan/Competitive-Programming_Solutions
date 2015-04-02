#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int V = 202;

int vs, es;
vector<int> g[V];
int lvl[V];
queue<int> q;
pair<int, int> ae[V * V];

int main()
{
	int i, j;
	int v1, v2;
	while (scanf("%d", &vs) == 1 && vs)
	{
		for (i = 0; i < vs; i++)
		{
			g[i].clear();;
			lvl[i] = -1;
		}
		while (!q.empty()) q.pop();
		scanf("%d", &es);
		for (i = 0; i < es; i++)
		{
			scanf("%d%d", &v1, &v2);
			g[v1].push_back(v2);
			g[v2].push_back(v1);
			ae[i] = make_pair(v1, v2);
		}
		lvl[0] = 0;
		q.push(0);
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
		for (i = 0; i < es; i++)
			if (lvl[ae[i].first] % 2 == lvl[ae[i].second] % 2)
				break;
		puts(i == es ? "BICOLORABLE." : "NOT BICOLORABLE.");
	}
	return 0;
}
