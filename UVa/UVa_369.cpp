#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long int LLU;
const int N = 102;
const int M = 102;

LLU c[N][M];

LLU cal(const int &n, const int &m)
{
	LLU &cur = c[n][m];
	if (cur) return cur;
	if (n == m || m == 0) return cur = 1ULL;
	return cur = cal(n-1, m-1) + cal(n-1, m);
}

int main()
{
	int n, m;
	memset(c, 0, sizeof(c));
	while (scanf("%d%d", &n, &m) == 2 && (n | m))
		printf("%d things taken %d at a time is %llu exactly.\n", n, m, cal(n, m));
	return 0;
}
