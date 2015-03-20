#include <cstdio>

using namespace std;

unsigned int raa(unsigned int n)
{
	if( n==0 ) return 0;
	int i, d[15], dc=0;
	unsigned int n1=n, n2;
	while( n>0 )
	{
		d[dc++]=n%10;
		n/=10;
	}
	n2=d[0];
	for( i=1; i<dc; i++ )
		n2=n2*10+d[i];
	return n1+n2;
}

bool isP(unsigned int n)
{
	int i, d[15], dc=0;
	while( n>0 )
	{
		d[dc++]=n%10;
		n/=10;
	}
	for( i=0; i<dc/2; i++ )
		if( d[i]!=d[dc-1-i] )
			return false;
	return true;
}

int main()
{
	int i, t, it;
	unsigned int n;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%u", &n);
		for( it=0; ; it++ )
		{
			if( isP(n) ) break;
			n=raa(n);
		}
		printf("%d %u\n", it, n);
	}
	return 0;
}
