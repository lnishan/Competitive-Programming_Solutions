#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pii;

struct node { pii l; int i; } rd[200005];
struct bridge
{
	ull l;
	int i;
	bool operator < (const bridge &b)const
	{
		return l < b.l;
	}
};
multiset<bridge> b;
int match[200005];

bool cmp_rd(node a, node b)
{
	if (a.l.second != b.l.second)
		return a.l.second < b.l.second;
	else
		return a.l.first < b.l.first;
}

bool cmp_bri(pii a, pii b)
{
	return a.first < b.first;
}

int main()
{
	int i, j, n, m;
	pii prev, ai;
	bridge tmp;
	scanf("%d%d", &n, &m);
	scanf("%I64u%I64u", &prev.first, &prev.second);
	for (i = 1; i < n; i++)
	{
		scanf("%I64u%I64u", &ai.first, &ai.second);
		rd[i - 1].l = make_pair(ai.first - prev.second, ai.second - prev.first);
		rd[i - 1].i = i - 1;
		prev = ai;
	}
	sort(rd, rd + n - 1, cmp_rd);
	for (i = 0; i < m; i++)
	{
		scanf("%I64u", &tmp.l);
		tmp.i = i;
		b.insert(tmp);
	}
	for (i = 0; i < n - 1; i++)
	{
		tmp.l = rd[i].l.first;
		auto it = b.lower_bound(tmp);
		if (it == b.end() || rd[i].l.second < (*it).l) break;
		match[rd[i].i] = (*it).i;
		b.erase(it);
	}
	if (i < n - 1)
		puts("No");
	else
	{
		puts("Yes");
		for (i = 0; i < n - 1; i++)
			printf("%d ", match[i] + 1);
		puts("");
	}
	return 0;
}