#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 5002

using namespace std;

int a[MAX], as[MAX], ah[MAX], nh, dp[MAX];

int getNh(int oh)
{
	int l = 0, h = nh, m;
	while (h-l > 1)
	{
		m = (l+h)>>1;
		if (ah[m] <= oh)
			l = m;
		else
			h = m;
	}
	return ah[l] == oh ? l : h;
}

int main()
{
	int i, j, k, n, newdph, nh1, nh2, minstp, ans, tmp;
	scanf("%d", &n);
	a[0] = 0; as[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		as[i] = a[i];
	}
	sort(as, as+n+1);
	nh = 0;
	ah[ nh++ ] = a[0];
	for (i = 1; i <= n; i++)
		if (as[i] != as[i-1])
			ah[ nh++ ] = as[i];
	
	dp[0] = 1;
	nh2 = getNh(a[1]);
	for (i = 1; i <= nh2; i++)
		dp[i] = 2;
	nh1 = nh2;
	
	for (i = 2; i <= n; i++)
	{
		nh2 = getNh(a[i]);
		newdph = min(nh1, nh2);
		minstp = dp[0];
		dp[0] = dp[0] + 1;
		for (j = 1; j < newdph; j++)
		{
			tmp=minstp;
			minstp = min(minstp, dp[j]);
			dp[j] = min(dp[j] + 1, tmp+2);
		}
		if (nh1 >= nh2)
			dp[nh2] = dp[nh2];
		else
		{
			minstp = min(minstp, dp[newdph]);
			for (j = newdph+1; j < nh2; j++)
				dp[j] = minstp + 1;
		}
		nh1 = nh2;
	}
	
	ans = dp[0];
	for (i = 1; i <= nh1; i++)
		ans = min(ans, dp[i]);
	
	printf("%d\n", ans);
	return 0;
}
