#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef unsigned long long int LLU;
int a[100002];
int cnt[1000002];
LLU l[50002];

int main()
{
	int i, n, it = 0;
	LLU ans = 0;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	sort(a, a+n);
	for (i = n-1; i >= 0; i--)
	{
		if (cnt[a[i]] >= 2)
		{
			l[it++] = a[i];
			cnt[a[i]] -= 2;
			if (it % 2 == 0) ans += l[it-1] * l[it-2]; 
		}
		else if (cnt[a[i]] == 1 && cnt[a[i]-1] > 0)
		{
			l[it++] = a[i]-1;
			cnt[a[i]]--;
			cnt[a[i]-1]--;
			if (it % 2 == 0) ans += l[it-1] * l[it-2]; 
		}
	}
	if (it < 2)
		puts("0");
	else
		printf("%I64u\n", ans);
	return 0;
}
