#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[40];

int main()
{
	int i, j, n, t=0, l, f;
	while( scanf("%d", &n)==1 )
	{
		memset(a, 0, sizeof(a));
		l=0;
		printf("case %d:\n", ++t);
		for( i=0; i<=(1<<n)-1; i++ )
		{
			putchar('{');
			f=0;
			for( j=0; j<l; j++ )
				if( a[j]>0 )
				{
					if( f>0 ) putchar(',');
					f=1;
					printf("%d", j+1);
				}
			puts("}");
			a[0]++;
			for( j=0; a[j]>1; j++ )
			{
				a[j]-=2;
				a[j+1]++;
			}
			l=max(l, j+1);
		}
		putchar('\n');
	}
	return 0;
}
