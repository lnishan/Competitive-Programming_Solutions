#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int t, sq;
	unsigned int n;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%u", &n);
		sq=sqrt(n);
		if( sq*sq==n )
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
