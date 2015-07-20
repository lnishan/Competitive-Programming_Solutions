#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii a[1002];

int main()
{
	freopen("knockout.in", "r", stdin);
	freopen("knockout.out", "w", stdout);
	int i, j, n, m;
	int st, ed, t, l, c, p, ans;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
	while (m--)
	{
		ans = 0;
		scanf("%d%d%d", &st, &ed, &t);
		for (i = 0; i < n; i++)
		{
			if (a[i].second >= a[i].first)
			{
				l = a[i].second - a[i].first;
				c = t / l;
				if (c & 1) // b to a
					p = a[i].second - t % l;
				else
					p = a[i].first + t % l;
			}
			else
			{
				l = a[i].first - a[i].second;
				c = t / l;
				if (c & 1)
					p = a[i].second + t % l;
				else
					p = a[i].first - t % l;
			}
			if (st <= p && p <= ed) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
