#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int V = 100005;
const int E = 100005;

vector<int> g[V];
pii ae[E];
ll lvl[V];
int max_compo = 1;
char odd = 0;

ll get_ans(int st)
{
	int i;
	ll cnt[2] = {1, 0};
	queue<int> q;
	lvl[st] = 0;
	q.push(st);
	while (!q.empty())
	{
		int vi = q.front(); q.pop();
		for (i = 0; i < g[vi].size(); i++)
		{
			int &vj = g[vi][i];
			if (lvl[vj] == -1)
			{
				lvl[vj] = lvl[vi] + 1;
				cnt[lvl[vj] & 1]++;
				q.push(vj);
			}
		}
	}
	max_compo = max((ll)max_compo, cnt[0] + cnt[1]);
	if (cnt[0] + cnt[1] > 2)
		return cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
	else
		return 0;
}

int main()
{
	int i, v, e, vi, vj;
	ll ans;
	scanf("%d%d", &v, &e);
	if (e == 0)
		printf("3 %I64d\n", (ll)v * (v - 1) * (v - 2) / 6);
	else
	{
		fill(lvl+1, lvl+1 + v, -1);
		for (i = 0; i < e; i++)
		{
			scanf("%d%d", &vi, &vj);
			g[vi].push_back(vj);
			g[vj].push_back(vi);
			ae[i].first = vi;
			ae[i].second = vj;
		}		
		for (i = 1; i <= v; i++)
			if (lvl[i] == -1)
				ans += get_ans(i);
		for (i = 0; i < e; i++)
			if (lvl[ae[i].first] % 2 == lvl[ae[i].second] % 2)
				odd = 1;
		if (odd == 1)
			puts("0 1");
		else if (max_compo > 2)
			printf("1 %I64d\n", ans);
		else
			printf("2 %I64d\n", (ll)e * (v - 2));
	}
	return 0;
}