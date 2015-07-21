#include <cstdio>
#define MAX 302

using namespace std;

char h[MAX]={0};

int main()
{
	int i, p, n, a;
	scanf("%d%d", &p, &n);
	for( i=1; i<=n; i++ )
	{
		scanf("%d", &a);
		if( h[a%p] )
		{
			printf("%d\n", i);
			break;
		}
		else
			h[a%p]=1;
	}
	if( i>n )
		puts("-1");
	return 0;
}
