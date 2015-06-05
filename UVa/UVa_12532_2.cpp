#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100002;

int n;
int a[N], f[2][N]; // f[0] => 0, f[1] => -1

void update(int num, int pos, const int &upd)
{
	if (num == -1) num = 1;
	while (pos <= n)
	{
		f[num][pos] += upd;
		pos += pos & (-pos);
	}
}

int query(int num, int pos)
{
	int ret = 0;
	if (num == -1) num = 1;
	while (pos >= 1)
	{
		ret += f[num][pos];
		pos -= pos & (-pos);
	}
	return ret;
}

void build()
{
	int i;
	for (i = 0; i < 2; i++)
		fill(f[i], f[i] + 1 + n, 0);
	for (i = 1; i <= n; i++)
		if (a[i] <= 0) update(a[i], i, +1);
}

int main()
{
	int i, q;
	char cmd; int x, y;
	int cnt;
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i]) a[i] = a[i] > 0 ? 1 : -1;
		}
		build(); // also init
		while (q--)
		{
			scanf(" %c %d %d", &cmd, &x, &y);
			if (cmd == 'C')
			{
				if (y) y = y > 0 ? 1 : -1;
				if (a[x] <= 0) update(a[x], x, -1);
				if (y <= 0) update(y, x, +1);
				a[x] = y;
			}
			else // if (cmd == 'P')
			{
				cnt = query(0, y) - query(0, x - 1);
				if (cnt)
					putchar('0');
				else
				{
					cnt = query(-1, y) - query(-1, x - 1);
					if (cnt & 1)
						putchar('-');
					else
						putchar('+');
				}
			}
		}
		puts("");
	}
	return 0;
}