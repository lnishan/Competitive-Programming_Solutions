#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100002;
int t[N << 2];
int n, q, a[N], f[N];

void build(int idx, const int &lb, const int &ub)
{
	if (lb == ub) 
	{
		t[idx] = f[lb];
		return ;
	}
	int mid = (lb + ub) >> 1;
	int l = (idx << 1) + 1, r = (idx << 1) + 2;
	build(l, lb, mid);
	build(r, mid+1, ub);
	t[idx] = max(t[l], t[r]);
}

int query(int idx, const int &lb, const int &ub, const int &qlb, const int &qub)
{
	if (lb == qlb && ub == qub)
		return t[idx];
	int mid = (lb + ub) >> 1;
	int l = (idx << 1) + 1, r = (idx << 1) + 2;
	int ret = 0;
	if (qlb <= mid)
		ret = max(ret, query(l, lb, mid, qlb, min(qub, mid)));
	if (qub > mid)
		ret = max(ret, query(r, mid+1, ub, max(mid+1, qlb), qub));
	return ret;
}

int main()
{
	int i, j, k, max_f, lb, ub, qlb, qub;
	while (scanf("%d", &n) == 1 && n)
	{
		scanf("%d", &q);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n && a[j] == a[i]; j++) ;
			for (k = i; k < j; k++)
				f[k] = j - i;
			i = j - 1;
		}
		build(0, 0, n - 1);
		for (i = 0; i < q; i++)
		{
			scanf("%d%d", &qlb, &qub);
			--qlb; --qub;
			if (a[qlb] == a[qub])
			{
				printf("%d\n", qub - qlb + 1);
				continue;
			}
			else
			{
				ub = upper_bound(a, a + n, a[qlb]) - (&a[0]) - 1;
				max_f = ub - qlb + 1;
				lb = lower_bound(a, a + n, a[qub]) - (&a[0]);
				max_f = max(max_f, qub - lb + 1);
				
				if (ub + 1 <= lb - 1)
					max_f = max(max_f, query(0, 0, n - 1, ub + 1, lb - 1));
				printf("%d\n", max_f);
			}
		}
	}
	return 0;
}
