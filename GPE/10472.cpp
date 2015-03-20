#include <cstdio>

using namespace std;

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d%d", &n, &m);
		if( (n-1)%(m-1)==0 )
			printf("%d\n", (n-1)/(m-1));
		else
			puts("cannot do this");
	}
	return 0;
}
