#include <cstdio>

using namespace std;

int w[102];
struct edge{
	int s, e, w;
} g[102];

int main()
{
	int i, j, n, m, s, l, wt;
	char c[3];
	while( scanf("%d", &n)==1 && n>0 )
	{
		for( i=0; i<=n; i++ )
			w[i]=0; // connect all vertices to, say -1 as a starting vertex
		scanf("%d", &m);
		for( i=0; i<m; i++ )
		{
			scanf("%d %d %s %d", &s, &l, &c, &wt);
			if( c[0]=='l' ) // lt
				g[i]= (edge){ s+l, s-1, wt-1 };
			else // gt
				g[i]= (edge){ s-1, s+l, -(wt+1) };
		}
		for( i=0; i<n; i++ ) // n+1 vertices
			for( j=0; j<m; j++ )
				if( w[ g[j].s ] + g[j].w < w[ g[j].e ] )
					w[ g[j].e ] = w[ g[j].s ] + g[j].w;
		// searching for negative cycle
		for( i=0; i<m; i++ )
			if( w[ g[i].s ] + g[i].w < w[ g[i].e ] )
				break;
		if( i==m ) // no negative cycle
			puts("lamentable kingdom");
		else
			puts("successful conspiracy");
	}
	return 0;
}
