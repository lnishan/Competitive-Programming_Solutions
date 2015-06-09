#include <cstdio>

using namespace std;

int main()
{
	int v, t;
	while (scanf("%d%d", &v, &t) == 2)
		printf("%d\n", ((v * t) << 1));
	return 0;
}