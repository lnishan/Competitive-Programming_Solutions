#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAX 100005

using namespace std;

int a[2][MAX];
map<int, int> m, tm;
map<int, int>::iterator it;

int main()
{
	int i, j, k, n, ai, ans[2];
	m.clear();
	scanf("%d", &n);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < n - i; j++)
			scanf("%d", &a[i][j]);
	}
	for (i = 0; i < n - 2; i++)
	{
		scanf("%d", &ai);
		it = m.find(ai);
		if (it == m.end())
			m[ai] = 1;
		else
			(it->second)++;
	}
	for (i = 1; i >= 0; i--)
	{
		tm = m;
		for (j = 0; j < n - i; j++)
		{
			it = tm.find(a[i][j]);
			if (it == tm.end())
			{
				ans[i] = a[i][j];
				m[ a[i][j] ] = 1;
			}
			else if (it->second == 0)
			{
				ans[i] = a[i][j];
				m[ a[i][j] ]++;
			}
			else
				(it->second)--;
		}
	}
	printf("%d\n%d\n", ans[0], ans[1]);
	return 0;
}
