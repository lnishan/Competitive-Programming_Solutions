#include <cstdio>
#include <algorithm>

using namespace std;

long long int a[100002];

inline long long int absn(long long int n)
{
	return n>0?n:-n;
}

int main()
{
	int i, n, m;
	long long int diff, mxdiff, tot=0;
	scanf("%d%d", &n, &m);
	scanf("%I64d", &a[1]);
	for( i=2; i<=m; i++ )
	{
		scanf("%I64d", &a[i]);
		diff=absn(a[i]-a[i-1]);
		tot+=diff;
	}
	if( m>=2 )
	{
		mxdiff=absn(a[1]-a[2]);
		mxdiff=max(mxdiff, absn(a[m-1]-a[m]));
		for( i=2; i<m; i++ )
			mxdiff=max(mxdiff, absn(a[i]-a[i-1]) + absn(a[i]-a[i+1]) - absn(a[i-1]-a[i+1]));
	}
	else
		mxdiff=0;
	
	printf("%I64d", tot-mxdiff);
	return 0;
}
