#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

char s[N];
int dp[N];

int main()
{
	int i, j, k, n, ans = 0;
	scanf("%d ", &n);
	gets(s);
	dp[0] = 1;
	for (i = 1; i < n; i++)
		if (s[i] != s[i - 1])
			dp[i] = dp[i - 1] + 1;
		else
			dp[i] = 1;
	for (i = 0; i < n; i++)
	{
		int tmp = dp[i];
		j = i + dp[i];
		if (j < n)
		{
			tmp += dp[j];
			k = j + dp[j];
			if (k < n)
				tmp += dp[k];
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
