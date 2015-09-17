#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int i, n, ox, oy, x, y;
	while (scanf("%d", &n) == 1 && n)
	{
		scanf("%d%d", &ox, &oy);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			x -= ox; y -= oy;
			if (!x || !y)
				puts("divisa");
			else if (x > 0 && y > 0)
				puts("NE");
			else if (x > 0 && y < 0)
				puts("SE");
			else if (x < 0 && y > 0)
				puts("NO");
			else
				puts("SO");
		}
	}
	return 0;
}
