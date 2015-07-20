#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

int af[102];
char d[1002][1002];
char s[1005];
char val[1005];
char pos[1005];

int main()
{
	freopen("filter.in", "r", stdin);
	freopen("filter.out", "w", stdout);
	int i, j, k, m, f, n, sh, sl;
	int q, uk;
	int ans = 0;
	scanf("%d%d", &m, &f);
	for (i = 0; i < f; i++) scanf("%d", &af[i]);
	scanf("%d", &n);
	fill(pos, pos + n, 0);
	sl = (m - 1) / 4 + 1;
	for (i = 0; i < n; i++)
	{
		scanf(" "); gets(s);
		for (j = 0, sh = 0; j < sl; j++, sh += 4)
		{
			int tmp = isdigit(s[j]) ? s[j] - '0' : s[j] - 'a' + 10;
			for (k = 0; k < 4; k++)
				d[i][sh + k] = (tmp >> k) & 1;
		}
	}
//	for (i = 0; i < n; i++, puts(""))
//		for (j = 0; j < m; j++)
//			printf("%d ", d[i][j]);
	scanf("%d", &q);
	while (q--)
	{
//		puts("-");
		scanf("%d", &uk);
		fill(val, val + n, 1);
		for (i = 0; i < f; i++)
		{
			int tmp = (ll(uk) * af[i]) % m;
//			printf("%d\n", tmp);
			for (j = 0; j < n; j++)
				if (!d[j][tmp])
					val[j] = 0;
		}
		for (i = 0; i < n; i++)
			if (val[i])
				pos[i] = 1;
	}
	for (i = 0; i < n; i++)
		if (pos[i])
			ans++;
	printf("%d", ans);
	for (i = 0; i < n; i++)
		if (pos[i])
			printf(" %d", i);
	return 0;
}
