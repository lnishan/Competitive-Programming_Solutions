#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct itvl { int i, j; } a[100005];
itvl s[100005]; int top = 0;

int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &a[i].i, &a[i].j);
	sort(a, a + n, [](itvl a, itvl b){ return a.j != b.j ? a.j < b.j : a.i > b.i; });
	for (i = 0; i < n; i++)
	{
		if (top <= 0) { s[++top] = a[i]; continue; }
		if (a[i].i > s[top].i)
			s[++top] = a[i];
		else if (top <= 1 || a[i].i > s[top - 1].i)
			s[top] = a[i];
	}
	printf("%d\n", top);
	return 0;
}
