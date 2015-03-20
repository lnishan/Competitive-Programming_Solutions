#include <cstdio>

using namespace std;

int main()
{
	int n, p, tmp;
	while( scanf("%d", &n)==1 && n>0 )
	{
		tmp=0;
		while( n-- )
		{
			scanf("%d", &p);
			tmp^=p;
		}
		if( tmp )
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
