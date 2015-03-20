#include <cstdio>
#include <algorithm>
#define MAX 66

using namespace std;

int a[MAX], n, gExp, gSum;

bool dfs(int g, int left, int idx)
{
	if (g >= gExp) return true; // we can skip the gExp-th group
	int i, tmp, left2;
	bool ret;
	for (i = idx; i < n; i++)
		if (a[i] > 0 && a[i] <= left)
		{
			if (i > 0 && a[i] == a[i-1]) continue; // we've already tried the same element to be put into current group
			
			left2 = left - a[i]; // how much left to fill
			
			tmp = a[i];
			a[i] = 0; // used it
			
			if (left2 == 0) // no more => can start to create a new group
			{
				ret = dfs(g+1, gSum, 0);
				a[i] = tmp; // restore it
				return ret; // we're at a new group, but we are unable to allocate groups -> impossible
			}
			else
			{
				ret = dfs(g, left2, idx+1);
				a[i] = tmp; // restore it
				if (ret) return true;
			}
			
			if (left == gSum) // we're at the start of a new group, if we cannot allocate any element, then this path is def. impossible
				return false;
			
			
		}
	return false;
}

bool cmp(int a, int b){ return a > b; }

int main()
{
	int i, sum;
	while (scanf("%d", &n) == 1 && n > 0)
	{
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a+n, cmp);
		for (i = a[0]; i <= sum; i++)
		{
			if (sum % i == 0) // can possibly be divided into i groups
			{
				gExp = sum / i;
				gSum = i;
				if (dfs(1, gSum, 0)) break; // found solution
			}
		}
		printf("%d\n", gSum);
	}
	return 0;
}
