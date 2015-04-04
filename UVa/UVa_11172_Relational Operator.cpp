#include <cstdio>

using namespace std;

int main()
{
	int t, a, b;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a, &b);
		if (a < b)
			puts("<");
		else if (a > b)
			puts(">");
		else
			puts("=");
	}
	return 0;
}
