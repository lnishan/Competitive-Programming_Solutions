#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int sw[102], mn[32769];
queue<int> q;

int main()
{
	int i, j, k, t, n, m, qi, tmp;
	scanf("%d", &t);
	for( k=1; k<=t; k++ )
	{
		memset(mn, -1, sizeof(mn));
		while( !q.empty() )
			q.pop();
		scanf("%d%d", &n, &m);
		for( i=0; i<m; i++ )
		{
			scanf("%d", &sw[i]);
			for( j=1; j<n; j++ )
			{
				scanf("%d", &tmp);
				sw[i]=(sw[i]<<1) + tmp;
			}
		}
		mn[(1<<n)-1]=0;
		q.push( (1<<n)-1 );
		while( !q.empty() )
		{
			qi=q.front();
			if( qi==0 ) break;
			for( i=0; i<m; i++ )
			{
				tmp=qi^sw[i];
				if( mn[tmp]<0 )
				{
					mn[tmp]=mn[qi]+1;
					q.push(tmp);
				}
			}
			q.pop();
		}
		if( mn[0]<0 )
			printf("Case %d: IMPOSSIBLE\n", k);
		else
			printf("Case %d: %d\n", k, mn[0]);
	}
	return 0;
}
