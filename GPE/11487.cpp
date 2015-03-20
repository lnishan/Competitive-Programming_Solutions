#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int f[5000][1002], l[5000];

int main(){
	int i, j, n, ml;
	memset(f, 0, sizeof(f));
	f[1][0]=f[2][0]=l[1]=l[2]=1;
	for( i=3; i<=4786; i++ )
	{
		ml=max(l[i-2], l[i-1]);
		for( j=0; j<ml; j++ )
		{
			f[i][j]+=f[i-1][j]+f[i-2][j];
			if( f[i][j]>9 )
			{
				f[i][j]-=10;
				f[i][j+1]++;
			}
		}
		if( f[i][ml]>0 ) ml++;
		l[i]=ml;
		if( ml>1000 ){ printf("%d\n", i-1); break; }
	}
	while( scanf("%d", &n)==1 )
	{
		for( i=0; i<l[n]; i++ )
			putchar(48+f[n][l[n]-i-1]);
		putchar('\n');
	}
	return 0;
}
