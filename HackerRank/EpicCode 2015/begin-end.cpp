#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000005];
long long cnt[30] = {0};

int main()
{
	int i, l;
	long long ans;
	scanf("%d ", &l);
	gets(s);
	ans = l;
	for (i = 0; i < l; i++)
		cnt[s[i] - 'a']++;
	for (i = 0; i < 26; i++)
		if (cnt[i])
			ans += cnt[i] * (cnt[i] - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}
