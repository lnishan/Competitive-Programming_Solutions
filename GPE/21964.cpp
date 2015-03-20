#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];

int main()
{
	int i, j, n, c, l, m, h, cc, curc;
	while( scanf("%d%d", &n, &c)==2 )
	{
		l=0; h=0;
		for( i=0; i<n; i++ )
		{
			scanf("%d", &a[i]);
			l=max(l, a[i]);
			h+=a[i];
		}
		l--;
		while( h-l>1 )
		{
			m=(l+h)/2;
			cc=1; curc=0;
			for( i=0; i<n; i++ )
			{
				if( curc+a[i]>m )
				{
					cc++;
					curc=a[i];
				}
				else
					curc+=a[i];
			}
			if( cc<=c )
				h=m;
			else
				l=m;
		}
		printf("%d\n", h);
	}
	return 0;
}
