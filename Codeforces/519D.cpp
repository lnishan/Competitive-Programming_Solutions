#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100005
typedef long long int LLD;

using namespace std;

LLD pre[MAX], sc[26];
LLD dis[MAX]; int it; 
LLD cnt[26][MAX];
char s[MAX];
int l;

inline int num(const LLD &n)
{
	int l = 0, h = it, m;
	while (h - l > 1)
	{
		m = (l + h) >> 1;
		if (dis[m] == n) return m;
		else if (dis[m] < n)
			l = m;
		else
			h = m;
	}
	return l;
}

int main()
{
	int i, j, k;
	LLD ans = 0;
	for (i = 0; i < 26; i++)
		scanf("%I64d", &sc[i]);
	memset(dis, -1, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	pre[0] = 0;
	it = 0;
	scanf(" ");
	gets(s);
	l = strlen(s);
	for (i = 1; i <= l; i++)
		pre[i] = pre[i-1] + sc[s[i-1] - 'a'];
	sort(pre, pre + l + 1);
	for (i = 0; i <= l; i++)
	{
		dis[ it++ ] = pre[i];
		for (j = i+1; j <= l && pre[j] == pre[i]; j++) ;
		i = j - 1;
	}
	pre[0] = 0;
	for (i = 1; i <= l; i++)
	{
		cnt[s[i-1] - 'a'][ num(pre[i-1]) ] ++;
		pre[i] = pre[i-1] + sc[s[i-1] - 'a'];
	}
	for (i = 1; i <= l; i++)
	{
		cnt[s[i-1] - 'a'][ num(pre[i-1]) ]--;
		LLD &c = cnt[s[i-1] - 'a'][ num(pre[i]) ];
		if (c > 0)
			ans += c;
	}
	printf("%I64d\n", ans);
	return 0;
}
