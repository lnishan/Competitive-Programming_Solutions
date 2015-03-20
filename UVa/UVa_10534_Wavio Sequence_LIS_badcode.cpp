#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10005

using namespace std;

int a[MAX], n;
int lis[MAX], lisDP[MAX];
int lisR[MAX], lisRDP[MAX];

int binSearch(int a[], int top, int q)
{
	int l = 0, h = top+1, m;
	while ( h-l > 1 )
	{
		m = (l + h) >> 1;
		if (a[m] >= q)
			h = m;
		else
			l = m;
	}
	return (a[l] >= q) ? l : h;
}
void exec_lis()
{
	int i, top = -1;
	for (i = 0; i < n; i++)
	{
		if ( top < 0 || (top >= 0 && a[i] > lis[top]) )
			lis[++top] = a[i];
		else
			lis[ binSearch(lis, top, a[i]) ] = a[i];
		lisDP[i] = top+1;
	}
	return ;
}
void exec_lisR()
{
	int i, top = -1;
	for (i = n-1; i >= 0; i--)
	{
		if ( top < 0 || (top >= 0 && a[i] > lisR[top]) )
			lisR[++top] = a[i];
		else
			lisR[ binSearch(lisR, top, a[i]) ] = a[i];
		lisRDP[i] = top+1;
	}
	return ;
}

int main()
{
	int i, ans;
	while (scanf("%d", &n) == 1)
	{
		ans = 1;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		exec_lis();
		exec_lisR();
		for (i = 0; i < n; i++)
			ans = max(ans, min(lisDP[i], lisRDP[i])*2 - 1);
		printf("%d\n", ans);
	}
	return 0;
}
