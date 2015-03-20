#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[1000002];
char v[1000002];
int n, ts, order[1000002];

bool dfs(int i)
{
	int j;
	bool ret;
	
	for( j=0; j<g[i].size(); j++ )
	{
		int &ed=g[i][j];
		if( v[ed]==1 )
			return false;
		else if( v[ed]!=2 )
		{
			v[ed]=1;
			ret=dfs(ed);
			v[ed]=2;
			if( !ret )
				return false;
		}
	}
	
	order[ts--]=i;
	return true;
}

int main()
{
	int i, j, m, a, b;
	bool ret;
	while( scanf("%d%d", &n, &m)==2 && !(n==0 && m==0) )
	{
		for( i=1; i<=n; i++ )
		{
			g[i].clear();
			v[i]=0;
		}
		while( m-- )
		{
			scanf("%d%d", &a, &b);
			g[a].push_back(b);
		}
		ts=n-1;
		for( i=1; i<=n; i++ )
			if( !v[i] )
			{
				v[i]=1;
				ret=dfs(i);
				if( !ret )
					break;
				v[i]=2;
			}
		
		if( ret )
			for( i=0; i<n; i++ )
				printf("%d\n", order[i]);
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
