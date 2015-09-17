#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int ans = 0;
map<int, int> dp;
int ax[100005], ah[100005];

void upd(int x, int v)
{
	ans = max(ans, v);
	auto it = dp.find(x);
	if (it == dp.end())
		dp[x] = v;
	else
		it->second  = max(it->second, v);
	printf("Update dp[%d] = %d\n", x, v);
}

int main()
{
	int i, n, x, h;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d%d", &ax[i], &ah[i]);
	for (i = 0; i < n; i++)
	{
		int &x = ax[i], &h = ah[i];
		auto it = dp.lower_bound(x - h);
		if (it != dp.begin())
		{
			puts("hi");
			it--;
			int j = lower_bound(ax, ax + n, x - h) - ax;
			if (j >= n || (j < n && ax[j] > x)) upd(x, it->second + 1);
		}
		it = dp.lower_bound(x);
		if (it != dp.begin())
		{
			puts("hi2");
			it--;
			upd(x, it->second);
			int j = lower_bound(ax, ax + n, x) - ax;
			cout << "*" << j << endl;
			if (j >= n || (j < n && ax[j] > x + h)) upd(x + h, it->second + 1);
		}
		else
			upd(x, 1);
	}
	printf("%d\n", ans);
	return 0;
}
