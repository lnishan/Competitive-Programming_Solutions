#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200005;
int a[N];
int lis[N], it;
int f[N], b[N];

int main()
{
	freopen("improvements.in", "r", stdin);
	freopen("improvements.out", "w", stdout);
	int i, n, p;
	int ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		a[p] = i;
	}
	it = 0;
	lis[++it] = a[1];
	f[1] = 1;
	for (i = 2; i <= n; i++)
		if (a[i] > lis[it])
		{
			lis[++it] = a[i];
			f[i] = it;
		}
		else
		{
			p = upper_bound(lis + 1, lis + 1 + it, a[i]) - (&lis[0]);
			lis[p] = a[i];
			f[i] = p;
		}
	it = 0;
	lis[++it] = a[n];
	b[n] = 1;
	for (i = n - 1; i >= 1; i--)
		if (a[i] > lis[it])
		{
			lis[++it] = a[i];
			b[i] = it;
		}
		else
		{
			p = upper_bound(lis + 1, lis + 1 + it, a[i]) - (&lis[0]);
			lis[p] = a[i];
			b[i] = p;
		}
	for (i = 1; i <= n; i++)
		ans = max(ans, f[i] + b[i] - 1);
	printf("%d\n", ans);
	return 0;
}
			
