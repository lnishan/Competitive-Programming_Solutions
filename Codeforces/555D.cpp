#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int N = 200005;
pair<int, int> b[N];
int a[N], p[N];
int n;

int get_next(char dir, int idx, int len)
{
	if (dir)
		return upper_bound(a, a + n, a[idx] + len) - a - 1;
	else
		return lower_bound(a, a + n, a[idx] - len) - a;
}

int main()
{
	int i, m;
	int prev[2], to;
	char dir; int pos, len, next_pos;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; b[i].second = i, i++) scanf("%d", &b[i].first);
	sort(b, b + n);
	for (i = 0; i < n; i++) a[i] = b[i].first, p[b[i].second] = i;
	while (m--)
	{
		scanf("%d%d", &pos, &len); --pos;
		pos = p[pos];
		dir = 1;
		prev[0] = prev[1] = 1e9;
		for ( ; ; dir ^= 1, len -= abs(a[next_pos] - a[pos]), pos = next_pos)
		{
			next_pos = get_next(dir, pos, len);
			if (next_pos == pos && next_pos == prev[dir]) break;
			if (next_pos == prev[dir])
			{
				len %= abs(a[prev[dir]] - a[prev[dir ^ 1]]) << 1;
				next_pos = get_next(dir, pos, len);
			}
			prev[dir] = next_pos;
		}
		printf("%d\n", b[pos].second + 1);
	}
	return 0;
}