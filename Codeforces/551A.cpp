#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[2002];
int b[2002];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		a[i].first = i;
		scanf("%d", &a[i].second);
	}
	sort(a, a + n, cmp);
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n && a[j].second == a[i].second; j++) b[a[j].first] = i + 1;
		i = j - 1;
	}
	for (i = 0; i < n; i++)
		printf(i ? " %d" : "%d", b[i]);
	return 0;
}