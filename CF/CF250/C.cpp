#include <cstdio>
#include <algorithm>
#define INF 2147483647

using namespace std;

char g[1002][1002]={0}, r[1002]={0};
int c[1002]={0}, cr[1002]={0}, odeg[1002]={0};

int main()
{
	int i, j, n, m, s, e, mn, mnv, ans=0, mcost, tmp;
	scanf("%d%d", &n, &m);
	for( i=1; i<=n; i++ )
		scanf("%d", &c[i]);
	while( m-- )
	{
		scanf("%d%d", &s, &e);
		g[s][e]=g[e][s]=1;
		cr[s]+=c[e];
		cr[e]+=c[s];
		odeg[s]++;
		odeg[e]++;
	}
	for( i=1; i<=n; i++ )
	{
		mcost=INF;
		for( j=1; j<=n; j++ )
		{
			if( odeg[j]==0 )
				r[j]=1;
			if( !r[j] )
			{
				tmp=cr[j]-odeg[j]*c[j];
				if( tmp<mcost )
				{
					mcost=tmp;
					mn=cr[j];
					mnv=j;
				}
			}
		}
			
		if( mcost==INF )
			break;
		else
		{
			odeg[mnv]=0; r[mnv]=1;
			for( j=1; j<=n; j++ )
				if( g[mnv][j] )
				{
					g[mnv][j]=g[j][mnv]=0;
					cr[j]-=c[mnv];
					odeg[j]--;
				}
			ans+=mn;
		}
	}
	printf("%d", ans);
	return 0;
}
