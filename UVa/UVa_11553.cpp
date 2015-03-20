#include <cstdio>
#include <algorithm>

using namespace std;

const int INF=2147483647;
int n, m[8][8], p[8], ans;
char v[8]={0};

void dfs(int i)
{
	int j;
	if( i==n )
	{
		int sum=0;
		for( j=0; j<n; j++ )
			sum+=m[j][p[j]];
		ans=min(ans, sum);
		return ;
	}
	else
	{
		for( j=0; j<n; j++ )
			if( !v[j] )
			{
				p[i]=j;
				v[j]=1;
				dfs(i+1);
				v[j]=0;
			}
	}
}

int main()
{
	int i, j, t;
	scanf("%d", &t);
	while( t-- )
	{
		ans=INF;
		scanf("%d", &n);
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				scanf("%d", &m[i][j]);
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}
