#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int N = 100005;
const int A = 1000005;

int a[N];
int cnt[A];
int s[A], e[A];

int main()
{
	int i, n;
	int max_o = 0;
	int l, min_l = 1e9;
	int ans_s, ans_e;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (!cnt[a[i]]) s[a[i]] = e[a[i]] = i;
		++cnt[a[i]];
		e[a[i]] = max(e[a[i]], i);
	}
	for (i = 0; i < n; i++)
		max_o = max(max_o, cnt[a[i]]);
	for (i = 0; i < n; i++)
		if (cnt[a[i]] == max_o && (l = e[a[i]] - s[a[i]] + 1) < min_l)
		{
			min_l = l;
			ans_s = s[a[i]];
			ans_e = e[a[i]];
		}
	printf("%d %d\n", ans_s + 1, ans_e + 1);
	return 0;
}
