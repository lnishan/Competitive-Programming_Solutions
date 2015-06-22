#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;

int cnt[128];
char s[210005];

int main()
{
	int i, n, ans = 0;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d ", &n);
	gets(s);
	for (i = 0; i < (n-1) * 2; i++)
	{
		if (i % 2 == 0)
			cnt[toupper(s[i])] ++;
		else
		{
			if (cnt[s[i]])
				cnt[s[i]]--;
			else
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
