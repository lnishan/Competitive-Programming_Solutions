#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{	
	int i, n, mn[3], mx[3], tmp;
	scanf("%d", &n);
	for (i = 0; i < 3; i++)
		scanf("%d%d", &mn[i], &mx[i]);
	n -= mn[0] + mn[1] + mn[2];
	for (i = 0; i < 3 && n; i++)
	{
		tmp = min(n, mx[i] - mn[i]);
		n -= tmp;
		mn[i] += tmp;
	}
	printf("%d %d %d\n", mn[0], mn[1], mn[2]);
	return 0;
}