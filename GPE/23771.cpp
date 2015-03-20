#include <cstdio>
#include <cstring>

using namespace std;

unsigned long long int f[20];
char s[25], ans[25];

int main()
{
	int i, j, k, t, l;
	unsigned long long int n, c;
	f[0]=1;
	for( i=1; i<20; i++ )
		f[i]=f[i-1]*i;
	scanf("%d", &t);
	for( i=1; i<=t; i++ )
	{
		memset(ans, 0, sizeof(ans));
		printf("Case %d: ", i);
		scanf("%s %llu", &s, &n);
		n--;
		l=strlen(s);
		for( j=0; j<l; j++ )
		{
			c=n/f[l-j-1];
			n%=f[l-j-1];
			for( k=0; k<l; k++ )
				if( ans[k]==0 )
				{
					if( c==0 )
					{
						ans[k]=s[j];
						break;
					}
					c--;
				}
		}
		ans[l]='\0';
		puts(ans);
	}
	return 0;
}
