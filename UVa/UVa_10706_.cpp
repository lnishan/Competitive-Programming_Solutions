#include <cstdio>

using namespace std;

int a[31268], b[31268];

int getDgt(int n, int i)
{
	int d[15], dc=0;
	while( n>0 )
	{
		d[++dc]=n%10;
		n/=10;
	}
	return d[dc-i+1];
}

int main()
{
	int i, t, n, l, m, h, rest, tmp;
	a[0]=0;
	for( i=1; i<31268; i++ )
	{
		if( i>9999 )
			a[i]=a[i-1]+5;
		else if( i>999 )
			a[i]=a[i-1]+4;
		else if( i>99 )
			a[i]=a[i-1]+3;
		else if( i>9 )
			a[i]=a[i-1]+2;
		else
			a[i]=a[i-1]+1;
	}
	b[0]=0;
	for( i=1; i<31268; i++ )
		b[i]=b[i-1]+a[i];
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d", &n);
		l=0; h=31268;
		while( h-l>1 )
		{
			m=(l+h)/2;
			if( n>b[m] )
				l=m;
			else
				h=m;
		}
		rest=n-b[l];
		l=0; h=31268;
		while( h-l>1 )
		{
			m=(l+h)/2;
			if( rest>a[m] )
				l=m;
			else
				h=m;
		}
		rest-=a[l];
		printf("%d\n", getDgt(l+1, rest));
	}
	return 0;
}
