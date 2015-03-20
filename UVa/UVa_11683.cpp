#include <cstdio>

using namespace std;

int main()
{
	int i, h, l, ih, maxh, prevh, ans;
	while( scanf("%d", &h)==1 && h>0 )
	{
		ans=0;
		scanf("%d", &l);
		scanf("%d", &ih);
		maxh=prevh=ih;
		for( i=1; i<l; i++ )
		{
			scanf("%d", &ih);
			if( ih<prevh )
				ans+=prevh-ih;
			else if( ih>maxh )
			{
				ans+=ih-maxh;
				maxh=ih;
			}
			prevh=ih;
		}
		ans+=h-maxh;
		printf("%d\n", ans);
	}
	return 0;
}
