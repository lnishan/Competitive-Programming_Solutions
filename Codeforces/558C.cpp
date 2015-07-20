#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char a[100005][20];
int dgt[100005];

int main()
{
	int i, j, n, ai, tmp;
	int ans = 0;
	int max_dgt = 0, min_dgt;
	int d, lcd = 0;
	int min_zc = 1e9;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		fill(a[i], a[i] + 20, -1);
		scanf("%d", &ai);
		tmp = ai;
		for (dgt[i] = 0; tmp; tmp >>= 1) dgt[i]++;
		max_dgt = max(max_dgt, dgt[i]);
		for (j = dgt[i] - 1; j >= 0; j--)
			a[i][dgt[i] - 1 - j] = (ai >> j) & 1;
	}
	for (j = 0; j < max_dgt; j++)
	{
		d = a[0][j];
		for (i = 1; i < n; i++)
			if (a[i][j] ^ d)
				break;
		if (i < n) break;
	}
	lcd = j;
//	printf("lcd = %d\n", lcd);
	max_dgt = 0; min_dgt = 1e9;
	for (i = 0; i < n; i++)
	{
		for (j = lcd; a[i][j] != -1; j++)
			if (a[i][j] == 1)
			{
				ans += dgt[i] - j;
				dgt[i] = j;
				break;
			}
		min_dgt = min(min_dgt, dgt[i]);
		max_dgt = max(max_dgt, dgt[i]);
	}
//	printf("%d\n", ans);
	for (j = min_dgt; j <= max_dgt; j++)
	{
		tmp = 0;
		for (i = 0; i < n; i++)
			tmp += abs(dgt[i] - j);
		min_zc = min(min_zc, tmp);
	}
	ans += min_zc;
	printf("%d\n", ans);
	return 0;
}
	
