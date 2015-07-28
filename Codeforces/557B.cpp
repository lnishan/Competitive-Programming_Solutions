#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[200005];

int main()
{
	int i, n, w;
	int mn1 = 1e9, mn2 = 1e9;
	double ans;
	scanf("%d%d", &n, &w);
	for (i = 0; i < (n << 1); i++)
		scanf("%d", &a[i]);
	sort(a, a + (n << 1));
	for (i = 0; i < n; i++) mn1 = min(mn1, a[i]);
	for (i = n; i < (n << 1); i++) mn2 = min(mn2, a[i]);
//	printf("%d %d\n", mn1, mn2);
	ans = min(double(mn2) / 2, double(mn1));
	ans = min(ans * 3.0 * n, (double)w);
	printf("%.17f\n", ans);
	return 0;
}