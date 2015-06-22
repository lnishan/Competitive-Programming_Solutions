#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100005;

int a[N], b[N];

int main()
{
	int i, j, n, k, ans = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	for (i = j = n - 1; i >= 0 && j >= 0; i--, j--)
	{
		while (i >= 0 && a[i] > b[j] + k) --i;
		if (i < 0) break;
		while (j >= 0&& a[i] < b[j] - k) --j;
		if (j < 0) break;
		if (a[i] <= b[j] + k) ++ans; else ++j;
	}
	printf("%d\n", ans);
	return 0;
} 
