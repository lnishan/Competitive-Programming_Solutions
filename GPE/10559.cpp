#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int s[1001], f[3000], t[3000];

int main()
{
	int i, j, k, l=1, ml, n;
	memset(s, 0, sizeof(s));
	s[1]=1;
	f[0]=1;
	for( i=2; i<=1000; i++ )
	{
		memset(t, 0, sizeof(t));
		ml=l;
		for( j=0; j<l; j++ )
		{
			t[j]+=f[j]*i;
			for( k=j; t[k]>9; k++ )
			{
				t[k+1]+=t[k]/10;
				t[k]%=10;
				ml=max(ml, k+2);
			}
		}
		
		for( j=0; j<ml; j++ )
		{
			s[i]+=t[j];
			f[j]=t[j];
		}
		l=ml;
	}
	while( scanf("%d", &n)==1 )
		printf("%d\n", s[n]);
	return 0;
}
		
