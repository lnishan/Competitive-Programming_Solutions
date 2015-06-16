#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define inf 0x3fffffff

using namespace std;

int main()
{
	int i, j;
	int a[20];
	int ans = 0;
	int n, l, r, x;
	int ez, hd, sel, tot;
	int all, tmp;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	all = (1 << n) - 1;
	for (i = 0; i <= all; i++)
	{
		sel = 0;
		tot = 0;
		ez = inf; hd = 0;
		for (tmp = i, j = 0; j < n; tmp >>= 1, j++)
		{
			if (tmp & 1)
			{
				sel++;
				tot += a[j];
				ez = min(ez, a[j]);
				hd = max(hd, a[j]);
			}
		}
		if (sel < 2) continue;
		if (tot >= l && tot <= r && hd - ez >= x) ans++;
	}
	printf("%d\n", ans);
	return 0;
}