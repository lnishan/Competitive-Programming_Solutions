#include <cstdio>
#include <cstring>

using namespace std;

int a[20];
char s[105];

int main()
{
	int i, j, l, n, ans;
	a[0]=0;
	for( i=1; i<20; i++ )
	{
		if( i==10 ){ a[i]=0; continue; }
		a[i]=1;
		for( j=0; j<i; j++ )
		{
			a[i]*=i;
			a[i]%=10;
		}
		a[i]+=a[i-1];
		a[i]%=10;
	}
	while( gets(s) )
	{
		l=strlen(s);
		if( l==1 && s[0]=='0' ) break;
		if( l==1 )
			n=0;
		else if( l==2 )
			n=(s[0]-48);
		else
			n=(s[l-3]-48)*10+s[l-2]-48;
		ans=(4*(n/2))%10;
		if( n%2==1 )
		{
			ans=(ans+7)%10;
			ans=(ans+a[10+s[l-1]-48])%10;
		}
		else
			ans=(ans+a[s[l-1]-48])%10;
		printf("%d\n", ans);
	}
	return 0;
}
