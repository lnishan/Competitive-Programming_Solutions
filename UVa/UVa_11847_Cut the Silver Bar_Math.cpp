#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int i, n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (i = 14; i >= 0; i--)
			if (n & (1 << i)) break;
		printf("%d\n", i);
	}
	return 0;
}