#include <cstdio>

using namespace std;

int main()
{
	int t;
	int x, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &x, &k);
		if (x % k)
			printf("%d %d\n", -x, x);
		else
			printf("%d 0\n", k);
	}
	return 0;
}