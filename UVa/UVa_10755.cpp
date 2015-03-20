#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_V 22

using namespace std;

long long int s[MAX_V][MAX_V][MAX_V];

int main()
{
	int i, j, k, l, m, n, t, a, b, c;
	long long int tmp, ans;
	memset(s, 0, sizeof(s));
	scanf("%d", &t);
	while( t-- )
	{
		ans=-1000000000000L;
		scanf("%d%d%d", &a, &b, &c);
		for( i=1; i<=a; i++ )
			for( j=1; j<=b; j++ )
				for( k=1; k<=c; k++ )
				{
					scanf("%lld", &tmp);
					s[i][j][k]=s[i-1][j][k] + s[i][j-1][k] + s[i][j][k-1] - s[i][j-1][k-1] - s[i-1][j][k-1] - s[i-1][j-1][k] + s[i-1][j-1][k-1] + tmp; 
				}
		for( i=1; i<=a; i++ )
			for( j=1; j<=b; j++ )
				for( k=1; k<=c; k++ )
					for( l=1; l<=i; l++ )
						for( m=1; m<=j; m++ )
							for( n=1; n<=k; n++ )
								ans=max(ans, s[i][j][k] - s[i-l][j][k] - s[i][j-m][k] - s[i][j][k-n] + s[i][j-m][k-n] + s[i-l][j][k-n] + s[i-l][j-m][k] - s[i-l][j-m][k-n]);
		printf("%lld\n", ans);
		if( t>0 ) putchar('\n');
	}
	return 0;
}
