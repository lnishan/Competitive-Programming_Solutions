#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	int i, j;
	ll a[200];
	ll w, m;
	fill(a, a + 200, 0);
	scanf("%I64d%I64d", &w, &m);
	for (i = 0; m && i <= 100; i++, m /= w)
	{
		a[i] += m % w;
		if (a[i] >= w)
			a[i] -= w, a[i + 1]++;
		if (a[i] != w - 1 && !(a[i] <= 1)) break;
		if (a[i] > 1 && a[i] == w - 1)
			a[i] = 0, a[i + 1]++;
	}
	if (m)
		puts("NO");
	else if (a[i] != w - 1 && !(a[i] <= 1))
		puts("NO");
	else
		puts("YES");
	return 0;
}