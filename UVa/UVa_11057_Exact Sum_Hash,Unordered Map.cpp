#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#define INF 0x3fffffff

using namespace std;

const int N = 10002;

int a[N];
unordered_map<int, int> map_n;
unordered_map<int, int>::iterator it, it2;

int main()
{
	// freopen("11057.txt", "r", stdin);
	// freopen("11057_output.txt", "w", stdout);
	int i, j, n, m, ans, diff, min_diff, ans_i, ans_j;
	while (scanf("%d", &n) == 1)
	{
		min_diff = INF;
		map_n.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			it = map_n.find(a[i]);
			if (it == map_n.end())
				map_n[a[i]] = 1;
			else
				it->second ++;
		}
		scanf("%d", &m);
		for (i = 0; i < n; i++)
		{
			if (a[i] == (m >> 1))
			{
				it = map_n.find(a[i]);
				if (it != map_n.end() && it->second >= 2)
				{
					ans = a[i];
					break;
				}
			}
			it = map_n.find(a[i]);
			if (it != map_n.end())
			{
				map_n.erase(it);
				it2 = map_n.find(m - a[i]);
				if (it2 != map_n.end())
				{
					map_n.erase(it2);
					if ( (diff = abs(m - (a[i] << 1))) < min_diff)
					{
						min_diff = diff;
						ans = a[i];
					}
				}
			}
		}
		ans_i = min(ans, m - ans);
		ans_j = m - ans_i;
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans_i, ans_j);
	}
	return 0;
}
