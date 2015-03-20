#include <cstdio>
#include <algorithm>

using namespace std;

const int INF=2147483647;
int a[100000], n;

bool chkPos(int k)
{
	int i;
	for( i=1; i<n; i++ )
	{
		if( a[i]-a[i-1]==k )
			k--;
		else if( a[i]-a[i-1]>k )
			break;
	}
	return (i==n);
}

int main()
{
	int i, j, k, it, t, l, m, h;
	scanf("%d", &t);
	for( it=1; it<=t; it++ )
	{
		scanf("%d", &n);
		scanf("%d", &a[0]);
		l=h=a[0];
		for( i=1; i<n; i++ )
		{
			scanf("%d", &a[i]);
			if( i>1 )
				l=max(l, a[i]-a[i-1]);
			h=max(h, a[i]);
		}
		while( h-l>1 )
		{
			m=(l+h)/2;
			if( chkPos(m) )
				h=m;
			else
				l=m;
		}
		printf("Case %d: %d\n", it, h);
	}
	return 0;
}
