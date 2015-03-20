#include <cstdio>

using namespace std;

int f(int n)
{
	int s=0;
	while( n>0 )
	{
		s+=n%10;
		n/=10;
	}
	return s;
}

int main()
{
	int n;
	while( scanf("%d", &n)==1 && n>0 )
	{
		while( n>9 )
			n=f(n);
		putchar(48+n);
		putchar('\n');
	}
}
