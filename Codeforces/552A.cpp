#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct rect
{
	int x1, y1, x2, y2;
} ar[102];

int main()
{
	int i, j, k, n, ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d%d%d", &ar[i].x1, &ar[i].y1, &ar[i].x2, &ar[i].y2);
	for (i = 1; i <= 100; i++)
		for (j = 1; j <= 100; j++)
			for (k = 0; k < n; k++)
				if (ar[k].x1 <= i && i <= ar[k].x2
					&& ar[k].y1 <= j && j <= ar[k].y2)
						ans++;
	printf("%d\n", ans);
//	while (1);
	return 0;
}