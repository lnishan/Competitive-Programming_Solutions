#include <cstdio>

using namespace std;

int main()
{
	int i, j, t, a[10], n;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d", &n);
		if( n==1 )
			puts("1");
		else
		{
			for( i=9; i>=2; i-- )
			{
				a[i]=0;
				while( n%i==0 )
				{
					n/=i;
					a[i]++;
				}
			}
			if( n>1 )
				puts("-1");
			else
			{
				for( i=2; i<=9; i++ )
					 for( j=0; j<a[i]; j++ )
					 	putchar(48+i);
				putchar('\n');
			}
		}
	}
	return 0;
}
