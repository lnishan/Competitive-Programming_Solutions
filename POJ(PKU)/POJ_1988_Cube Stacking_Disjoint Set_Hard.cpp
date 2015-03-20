#include <cstdio>
#include <cstring>
#define MAX 30005

using namespace std;

int f[MAX], cnt[MAX], ans[MAX];

int findF(int idx)
{
	if (f[idx] == idx) return idx;
	int preF = f[idx],
	newF = findF(f[idx]);
	ans[idx] += ans[preF];
	return f[idx] = newF;
}

void unionF(int i1, int i2)
{
	int f1 = findF(i1), f2 = findF(i2);
	f[f1] = f2;
	ans[f1] += cnt[f2];
	cnt[f2] += cnt[f1];
}

int main()
{
	int i, p, x, y;
	char cmd[3];
	while (scanf("%d", &p) == 1)
	{
		for (i = 1; i < MAX; i++)
		{
			f[i] = i;
			cnt[i] = 1;
			ans[i] = 0;
		}
		while (p--)
		{
			scanf("%s %d", cmd, &x);
			if (cmd[0] == 'M')
			{
				scanf("%d", &y);
				if (x != y) unionF(x, y);
			}
			else
			{
				findF(x);
				printf("%d\n", ans[x]);
			}
		}
	}
	return 0;
}
