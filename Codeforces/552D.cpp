#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define eps 1e-9
#define INF 1e9

using namespace std;

typedef long long ll;
typedef pair<double, double> pl;

struct cmp
{
	bool operator ()(pl a, pl b)
	{
		if (fabs(a.first - b.first) >= eps)
			return a.first < b.first;
		else if (fabs(a.second - b.second) >= eps)
			return a.second < b.second;
		else
			return false;
	}
};
map<pl, ll, cmp> mm;
map<pl, ll, cmp>::iterator it;

struct pt { int x, y; } a[2002];

int main()
{
	int i, j, k, n, cf;
	ll ans = 0;
	int x, y;
	pl tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			tmp = a[i].x == a[j].x ? 
				make_pair((double)INF, (double)a[i].x) : 
				make_pair(double(a[j].y - a[i].y) / (a[j].x - a[i].x), double(a[i].y * a[j].x - a[j].y * a[i].x) / (a[i].x - a[j].x));
			it = mm.find(tmp);
			if (it == mm.end())
				mm[tmp] = 1;
			else
				(it->second)++;
//			printf("%d %d %.3f\n", i, j, m);
		}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			tmp = a[i].x == a[j].x ? 
				make_pair((double)INF, (double)a[i].x) : 
				make_pair(double(a[j].y - a[i].y) / (a[j].x - a[i].x), double(a[i].y * a[j].x - a[j].y * a[i].x) / (a[i].x - a[j].x));
			it = mm.find(tmp);
			k = it->second;
			if (k == 1)
				ans += n - 2;
			else
			{
				cf = (sqrt(1 + 8 * k) + eps - 1) / 2;
				ans += n - 2 - (cf - 1);
			}
		}
	printf("%I64d\n", ans / 3);
	return 0;
}