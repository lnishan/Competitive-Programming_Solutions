#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

struct data
{
	int w, cap;
} a[5610];

int l[5610][2];

bool cmp(data a, data b)
{
	if( (a.cap-a.w)!=(b.cap-b.w) )
		return (a.cap-a.w)<(b.cap-b.w);
	else
		return a.cap<b.cap;
}

int main()
{
	int i, j, n=1, ans=0;
	while( scanf("%d%d", &a[n].w, &a[n].cap)==2 )
		n++;
	sort(a+1, a+n, cmp);
	n--;
	/*
	for( i=1; i<n; i++ )
		printf("%d %d\n", a[i].w, a[i].cap);
	while(1);
	*/
	l[0][0]=l[0][1]=0;
	for( i=1; i<=n; i++ )
		for( j=0; j<i; j++ )
			if( l[j][1]+a[i].w<=a[i].cap )
				if( l[j][0]+1>l[i][0] )
				{
					l[i][0]=l[j][0]+1;
					l[i][1]=l[j][1]+a[i].w;
				}
				else if( l[j][0]+1==l[i][0] )
				{
					if( l[j][1]+a[i].w < l[i][1] )
						l[i][1]=l[j][1]+a[i].w;
				}
	for( i=1; i<=n; i++ )
		ans=max(ans, l[i][0]);
	printf("%d\n", ans);
	return 0;
}
