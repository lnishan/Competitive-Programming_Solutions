#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	char used[10], exceed, found;
	int k, cases = 0;
	int n, m, t, f, g, h, i, j;
	while (scanf("%d", &n) == 1 && n)
	{
		if (cases++) puts("");
		found = 0;
		exceed = 0;
		for (f = 0; f < 10 && !exceed; f++)
			for (g = 0; g < 10 && !exceed; g++)
			{
				if (g == f) continue;
				for (h = 0; h < 10 && !exceed; h++)
				{
					if (h == g || h == f) continue;
					for (i = 0; i < 10 && !exceed; i++)
					{
						if (i == h || i == g || i == f) continue;
						for (j = 0; j < 10 && !exceed; j++)
						{
							if (j == i || j == h || j == g || j == f) continue;
							m = f * 10000 + g * 1000 + h * 100 + i * 10 + j;
							fill(used, used + 10, 0);
							used[f] = used[g] = used[h] = used[i] = used[j] = 1;
							if (m * n > 99999) { exceed = 1; break; }
							t = m * n;
							for (k = 0; k < 5; used[t % 10] = 1, t /= 10, k++)
								if (used[t % 10]) break;
							if (k == 5)
							{
								found = 1;
								printf("%05d / %05d = %d\n", m * n, m, n);
							}
						}
					}
				}
			}
		if (!found)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
