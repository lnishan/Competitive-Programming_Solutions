#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, ans;
	scanf("%d%d", &n, &m);
	ans = (n + m) / 3;
	ans = min(ans, n);
	ans = min(ans, m);
	printf("%d\n", ans);
	return 0;
}
