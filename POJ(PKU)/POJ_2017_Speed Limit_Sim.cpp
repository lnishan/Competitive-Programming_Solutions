#include <cstdio>

using namespace std;

int main()
{
	int n, s, t, pt, ans;
	while( scanf("%d", &n)==1 && n>0 )
	{
		ans=0;
		pt=0;
		while( n-- )
		{
			scanf("%d%d", &s, &t);
			ans+=s*(t-pt);
			pt=t;
		}
		printf("%d miles\n", ans);
	}
	return 0;
}
