#include <cstdio>
#include <cstring>
#define MAX 10002

using namespace std;

int prev[MAX];

int getD(int i)
{
	if( prev[i]==-1 )
		return 0;
	else
		return getD(prev[i])+1;
}

int main()
{
	int i, j, k, t, n, a, b, d1, d2, p1, p2;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d", &n);
		for( i=1; i<=n; i++ )
			prev[i]=-1;
		for( i=1; i<n; i++ )
		{
			scanf("%d%d", &a, &b);
			prev[b]=a;
		}
		scanf("%d%d", &a, &b);
		d1=getD(a);
		d2=getD(b);
		p1=a;
		p2=b;
		//printf("%d %d\n", d1, d2);
		while( d1>=0 && d2>=0 )
		{
			if( p1==p2 )
				break;
			else
			{
				if( d1>d2 )
				{
					p1=prev[p1];
					d1--;
				}
				else
				{
					p2=prev[p2];
					d2--;
				}
			}
		}
		printf("%d\n", p1);
	}
	return 0;
}