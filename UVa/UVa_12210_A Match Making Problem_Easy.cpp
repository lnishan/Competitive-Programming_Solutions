#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, b, c, ageB, ageC, minB, cases = 0;
	while (scanf("%d%d", &b, &c) == 2 && !(b == 0 && c == 0))
	{
		minB = 100;
		for (i = 0; i < b; i++)
		{
			scanf("%d", &ageB);
			minB = min(minB, ageB);
		}
		for (i = 0; i < c; i++)
			scanf("%d", &ageC);
		printf("Case %d: ", ++cases);
		if (b <= c)
			puts("0");
		else
			printf("%d %d\n", b - c, minB);
	}
	return 0;
}
