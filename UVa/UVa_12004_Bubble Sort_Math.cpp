#include <cstdio>

using namespace std;

typedef unsigned long long int LLU;

int main()
{
	int t;
	LLU n, ans;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		scanf("%lld", &n);
		ans = n * (n - 1);
		printf("Case %d: ", c);
		if (ans % 4 == 0)
			printf("%llu\n", ans / 4);
		else
			printf("%llu/%llu\n", ans / 2, 2);
	}
	return 0;
}
