#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
pii a[100];

int main()
{
	int i, n;
	int cnt, cnt_r = 0, cnt_l;
	int z;
	long long ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; cnt_r += (a[i].first > 0), i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	cnt_l = n - cnt_r;
	cnt = min(cnt_l, cnt_r);
	sort(a, a + n);
	z = lower_bound(a, a + n, make_pair(0, 0)) - a;
	for (i = 0; i < cnt; i++)
		ans += a[z + i].second + a[z - i - 1].second;
	if (cnt_l > cnt) ans += a[z - cnt - 1].second;
	if (cnt_r > cnt) ans += a[z + cnt].second;
	printf("%I64d\n", ans);
	return 0;
}
