#include <cstdio>

using namespace std;

char a[3651];

int main()
{
	int i, j, t, n, p, d, ans;
	scanf("%d", &t);
	while( t-- )
	{
		ans=0;
		scanf("%d", &n);
		for( i=1; i<=n; i++ )
			a[i]=0;
		scanf("%d", &p);
		while( p-- )
		{
			scanf("%d", &d);
			for( i=1; d*i<=n; i++ )
				a[d*i]=1;
		}
		for( i=1; i<=n; i++ )
			if( i%7!=6 && i%7!=0 && a[i]==1 )
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
