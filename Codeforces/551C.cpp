#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 100005, M = 100005;

int n, m, lz;
int a[N], b[N];

bool can(long long T)
{
	int i, j;
	long long t;
	for (i = 0; i <= lz; i++) b[i] = a[i];
	for (i = j = 0, t = T - 1; i <= lz && j < m; )
	{
		if (t < 0) return false;
		if (b[i] <= t)
			t -= b[i], i++, t--;
		else
			b[i] -= t, j++, t = T - i - 1;
		if (t < 0) j++, t = T - i - 1;
	}
	return i > lz;
}

int main()
{
	int i;
	long long lo, mid, hi;
	scanf("%d%d", &n, &m);
	lo = 0; hi = 0;
	for (i = 0; i < n; hi += a[i] + i + 1, lz = a[i] ? i : lz, i++)
		scanf("%d", &a[i]);
	while (lo < hi)
	{
		mid = (lo + hi) >> 1;
		if (can(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("%I64d\n", lo);
	return 0;
}