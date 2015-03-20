#include <cstdio>
#include <algorithm>
#define MAX 1002
#define INF 2147483647

using namespace std;

struct ele
{
	int idx;
	int w, s;
	bool operator < (ele &rhs) { return w < rhs.w && s > rhs.s; }
} a[MAX];
int dp[MAX], pre[MAX], stk[MAX];

bool cmp(ele a, ele b)
{
	if (a.w != b.w)
		return a.w < b.w;
	else
		return a.s > b.s;
}

int main()
{
	int i, j, n, maxN, maxI, curI, top;
	for (i = 1; scanf("%d%d", &a[i].w, &a[i].s) == 2; i++)
		a[i].idx = i;
	n = i-1;
	sort(a+1, a+1+n, cmp);
	a[0] = ele{0, 0, INF};
	dp[0] = 0;
	maxN = 0;
	for (i = 1; i <= n; i++)
	{
		dp[i] = 0;
		for (j = 0; j < i; j++)
			if (a[j] < a[i] && dp[j]+1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				pre[ a[i].idx ] = a[j].idx;
			}
		if (dp[i] > maxN)
		{
			maxN = dp[i];
			maxI = a[i].idx;
		}
	}
	printf("%d\n", maxN);
	curI = maxI;
	top = 0;
	while (curI != 0)
	{
		stk[++top] = curI;
		curI = pre[curI];
	}
	while (top)
		printf("%d\n", stk[top--]);
	return 0;
}
