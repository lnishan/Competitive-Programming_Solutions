#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 502

using namespace std;

vector<long long int> pr[MAX];
long long int a[MAX]; int m, k;

void prePrint(long long int n)
{
	long long int tmp = 0;
	int i, tmpcnt = 0;
	for (i = m-1; i >= 0; i--)
	{
		tmp += a[i];
		if (tmp > n || tmpcnt + i + 1 < k)
		{
			tmp = a[i];
			tmpcnt++;
		}
		pr[tmpcnt].push_back(a[i]);
	}
	return ;
}

void print()
{
	int i, j;
	for (i = k-1; i >= 0; i--)
	{
		for (j = pr[i].size()-1; j >= 0; j--)
		{
			printf("%lld", pr[i][j]);
			if (j > 0) putchar(' ');
		}
		if (i > 0) printf(" / ");
	}
	puts("");
	return ;
}

bool doable(long long int n)
{
	long long int tmp = 0;
	int i, tmpcnt = 0;
	for (i = 0; i < m; i++)
	{
		tmp += a[i];
		if (tmp > n)
		{
			tmp = a[i];
			tmpcnt++;
		}
	}
	tmpcnt ++;
	return tmpcnt <= k;
}

int main()
{
	int t, i;
	long long int low, mid, high;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &m, &k);
		low = 0; high = 1;
		for (i = 0; i < k; i++)
			pr[i].clear();
		for (i = 0; i < m; i++)
		{
			scanf("%lld", &a[i]);
			if (i <= m-k)
				high += a[i];
			low = max(low, a[i]);
		}
		while (high - low > 1)
		{
			mid = (low + high) >> 1;
			if (doable(mid))
				high = mid;
			else
				low = mid;
		}
		if (!doable(low))
			low = high;
		// printf("%d\n", low);
		prePrint(low);
		print();
	}
	return 0;
}
