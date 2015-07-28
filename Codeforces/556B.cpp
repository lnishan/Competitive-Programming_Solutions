#include <cstdio>

using namespace std;

int main()
{
	int i, n, d, tmp, ai;
	scanf("%d", &n);
	scanf("%d", &ai);
	d = (n - ai) % n;
	for (i = 1; i < n; i++)
	{
		scanf("%d", &ai);
		if ((ai - d * ((i & 1) * 2 - 1) + n) % n != i) break;
	}
	puts(i < n ? "No" : "Yes");
	return 0;
}