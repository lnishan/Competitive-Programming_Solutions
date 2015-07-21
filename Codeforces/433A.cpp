#include <cstdio>

using namespace std;

int main()
{
	int n, a, c1=0, c2=0, tot=0;
	scanf("%d", &n);
	while( n-- )
	{
		scanf("%d", &a);
		if( a==100 )
			c1++;
		else
			c2++;
		tot+=a;
	}
	tot>>=1;
	while( tot>=200 && c2>0 )
		tot-=200, c2--;
	while( tot>=100 && c1>0 )
		tot-=100, c1--;
	if( tot==0 )
		printf("YES");
	else
		printf("NO");
	return 0;
}
