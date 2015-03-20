#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int r[102][102];

int main()
{
	int i, j, k, t=0, a, b, mxn, tn, pc;
	while( scanf("%d%d", &a, &b)==2 && (a>0 && b>0) )
	{
		printf("Case %d: average length between pages = ", ++t);
		memset(r, 0, sizeof(r));
		tn=0; pc=0;
		r[a][b]=1;
		mxn=max(a, b);
		while( scanf("%d%d", &a, &b)==2 && (a>0 && b>0) )
		{
			r[a][b]=1;
			mxn=max(mxn, a);
			mxn=max(mxn, b);
		}
		for( k=1; k<=mxn; k++ )
			for( i=1; i<=mxn; i++ )
				for( j=1; j<=mxn; j++ )
					if( r[i][k]>0 && r[k][j]>0 )
					{
						if( r[i][j]==0 || r[i][k]+r[k][j]<r[i][j] )
							r[i][j]=r[i][k]+r[k][j];
					}
		for( i=1; i<=mxn; i++ )
			for( j=1; j<=mxn; j++ )
				if( i!=j && r[i][j]>0 )
				{
					pc++;
					tn+=r[i][j];
				}
		printf("%.3lf clicks\n", double(tn)/pc);
	}
	return 0;
}
