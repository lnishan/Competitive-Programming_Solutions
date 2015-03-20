#include <cstdio>
#include <algorithm>
#define N 1002

using namespace std;

struct job
{
	int id;
	int len, fine;
	bool operator < (const job &rhs)const
	{
		if (len * rhs.fine != rhs.len * fine)
			return len * rhs.fine < rhs.len * fine;
		else
			return id < rhs.id;
	}
} a[N];

int main()
{
	int i, t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			a[i].id = i;
			scanf("%d%d", &a[i].len, &a[i].fine);
		}
		sort(a+1, a+1+n);
		for (i = 1; i <= n; i++)
		{
			if (i > 1) putchar(' ');
			printf("%d", a[i].id);
		}
		puts("");
		if (t > 0) puts("");
	}
	return 0;
}
