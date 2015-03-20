#include <cstdio>

using namespace std;

int main(){
	long long int a, b, c, ans;
	while( scanf("%lld %lld",&a, &b)==2 )
	{
		c=a+b;
		while( a!=0 && b!=0 )
			if(a>b)
				a%=b;
			else
				b%=a;
		ans=c/( a==0?b:a ) -1;
		printf("%lld\n", ans);
	}
	return 0;
}
