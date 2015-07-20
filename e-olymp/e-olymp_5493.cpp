#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const ull M = 10000007;

ull ipow(ull a, ull p)
{
	ull t = a, ret = 1;
	for ( ; p; p >>= 1, t = (t * t) % M)
		if (p & 1)
			ret = (ret * t) % M;
	return ret;
}

int main()
{
	int n, k;
	ull ans;
	while (scanf("%d%d", &n, &k) == 2 && (n | k))
	{
		ans = 2 * ipow(n - 1, k) + ipow(n, k) +
			2 * ipow(n - 1, n - 1) + ipow(n, n);
		ans %= M;
		printf("%llu\n", ans);
	}
	return 0;
}
