#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[200005], stk[200005];

bool cmp(int a, int b) { return a > b; }

int main()
{
	int i, n, prev = 0x3fffffff, top = -1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i] -= n - i - 1;
	}
	sort(a, a + n, cmp);
	for (i = 0; i < n; prev = a[i] + i, i++)
		if (a[i] + i > prev)
			break;
		else
			stk[++top] = a[i] + i;
	if (i < n)
		puts(":(");
	else
		for (i = top; i >= 0; i--)
			printf(i ? "%d " : "%d", stk[i]);
	return 0;
}
