#include <cstdio>

using namespace std;

int main(){
	int i;
	long long int f[17], n;
	f[0]=1;
	for( i=1; i<17; i++ )
		f[i]=f[i-1]*i;
	while( scanf("%lld", &n)==1 && n>=0 )
	{
		if( n==0 )
			puts("0");
		else
		{
			n=(n+1)*n/2;
			for( i=16; i>=0; i-- )
				if( n>=f[i] )
					break;
			printf("%lld", n/f[i]);
			n%=f[i];
			for( i=i-1; i>=0; i-- )
			{
				printf(" %lld", n/f[i]);
				n%=f[i];
			}
			putchar('\n');
		}
	}
	return 0;
}
