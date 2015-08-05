#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;

int stk[N], top = 0;
int dp[N];

int main()
{
	int i, n, ai, tmp, ans = 0;
	scanf("%d", &n);
	scanf("%d", &ai);
	stk[++top] = ai;
	dp[1] = 0;
	for (i = 1; i < n; i++)
	{
		scanf("%d", &ai);
		if (stk[top] > ai)
		{
			stk[++top] = ai;
			dp[top] = 1; // + (top == 2);
		}
		else
		{
			for (tmp = 0; top && stk[top] <= ai; --top)
				tmp = max(tmp, dp[top] + 1);
			if (top)
				tmp = max(tmp, 1);
			else
				tmp = 0;
			stk[++top] = ai;
			dp[top] = tmp;
		}
		ans = max(ans, dp[top]);
	}
	printf("%d\n", ans);
	return 0;
}