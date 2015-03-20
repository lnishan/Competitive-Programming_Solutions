#include <cstdio>
#include <cstring>

using namespace std;

int a[50002], b[50002], c[50002];

int main()
{
	memset(a, -1, sizeof(a));
	int i, j, k, s, t, n;
	for( i=0; i<=223; i++ )
		for( j=i; j<=223; j++ )
			for( k=j; k<=223 && i*i+j*j+k*k<=50000; k++ )
			{
				s=i*i+j*j+k*k;
				if( a[s]<0 )
				{
					a[s]=i;
					b[s]=j;
					c[s]=k;
				}
			}
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d", &n);
		if( a[n]<0 )
			puts("-1");
		else
			printf("%d %d %d\n", a[n], b[n], c[n]);
	}
	return 0;
}
