#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char s[102]; int l;
char used[52];
int a[52];

inline bool valid(const int &m)
{
	return m >= 1 && m <= n && !used[m];
}

bool dfs(int si, int it)
{
	int i;
	if (it >= n) { for (i = 0; i < n; i++) printf("%d ", a[i]); return true; }
	if (si >= l) return false;
	bool ret;
	int m;
	m = s[si] - '0';
	if (valid(m))
	{
		used[m] = 1;
		a[it] = m;
		ret = dfs(si + 1, it + 1);
		if (ret) return true;
		used[m] = 0;
	}
	if (si >= l - 1) return false;
	m = (s[si] - '0') * 10 + s[si + 1] - '0';
	if (valid(m))
	{
		used[m] = 1;
		a[it] = m;
		ret = dfs(si + 2, it + 1);
		if (ret) return true;
		used[m] = 0;
	}
	return false;
}

int main()
{
	freopen("joke.in", "r", stdin);
	freopen("joke.out", "w", stdout);
	int i;
	gets(s); l = strlen(s);
	n = l < 10 ? l : 9 + (l - 9) / 2;
	fill(used + 1, used + 1 + n, 0);
	dfs(0, 0);
	return 0;
}
