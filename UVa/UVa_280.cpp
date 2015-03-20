#include <cstdio>
#include <cstring>

using namespace std;

char r[102][102], v[102];
int n;

void dfs(int i)
{
	int j;
	for( j=1; j<=n; j++ )
		if( r[i][j] && !v[j] )
		{
			v[j]=1;
			dfs(j);
		}
	return ;
}

int main()
{
	int i, j, s, e, sct, act;
	while( scanf("%d", &n)==1 && n>0 )
	{
		memset(r, 0, sizeof(r));
		while( scanf("%d", &s)==1 && s>0 )
		{
			while( scanf("%d", &e)==1 && e>0 )
				r[s][e]=1;
		}
		scanf("%d", &sct);
		while( sct-- )
		{
			memset(v, 0, sizeof(v));
			scanf("%d", &s);
			dfs(s);
			act=0;
			for( i=1; i<=n; i++ )
				if( !v[i] ) act++;
			printf("%d", act);
			for( i=1; i<=n; i++ )
				if( !v[i] )
					printf(" %d", i);
			putchar('\n');
		}
	}
	return 0;
}
