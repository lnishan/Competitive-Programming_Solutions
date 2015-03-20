#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500002;

long long int ans;
int a[N], t[N];

void merge(int l, int r)
{
	if (r <= l) return ;
	int i, i1, i2, m = (l + r) >> 1, l1 = (m - l + 1), l2 = (r - m);
	merge(l, m);
	merge(m+1, r);
	for (i = i1 = i2 = 0; i1 < l1 || i2 < l2; )
	{
		if (i1 >= l1) { t[i++] = a[m+1 + i2++]; continue; }
		if (i2 >= l2) { t[i++] = a[l   + i1++]; continue; }
		if (a[l + i1] > a[m+1 + i2])
		{
			t[i++] = a[m+1 + i2++];
			ans += l1 - i1;
		}
		else
			t[i++] = a[l   + i1++];
	}
	for (i = l; i <= r; i++)
		a[i] = t[i - l];
}

int main()
{
	int i, n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		ans = 0;
		merge(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}
