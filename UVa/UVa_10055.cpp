#include <cstdio>

using namespace std;

int main(){
	long long int a, b, c;
	while( scanf("%lld%lld", &a, &b)!=EOF )
	{
		c=a-b;
		if( c<0 )
			c=-c;
		printf("%lld\n", c);
	}
	return 0;
}
