#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int i, n, m;
	freopen("alter.in", "r", stdin);
	freopen("alter.out", "w", stdout);
	scanf("%d%d", &n, &m);
	printf("%d\n", n / 2 + m / 2);
	for (i = 2; i <= n; i += 2) printf("%d %d %d %d\n", i, 1, i, m);
	for (i = 2; i <= m; i += 2) printf("%d %d %d %d\n", 1, i, n, i);
	return 0;
}
