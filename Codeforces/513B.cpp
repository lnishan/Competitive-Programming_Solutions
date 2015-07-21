#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
int ans[52];
char choi[52];

int main()
{
	int i, n, l, r;
	ull m;
	scanf("%d%I64u", &n, &m); --m;
	for (i = n - 1; i >= 1; i--, m >>= 1) choi[i] = m & 1;
	for (l = 0, r = n - 1, i = 1; i <= n - 1; i++)
		if (choi[i])
			ans[r--] = i;
		else
			ans[l++] = i;
	ans[l] = n;
	for (i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}