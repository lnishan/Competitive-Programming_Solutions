#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int i, n, d, c[2] = {0};
	scanf("%d ", &n);
	char ch;
	for (i = 0; i < n; i++)
	{
		ch = getchar();
		c[ch - '0']++;
	}
	d = min(c[0], c[1]);
	c[0] -= d; c[1] -= d;
	printf("%d\n", c[0] + c[1]);
	return 0;
}