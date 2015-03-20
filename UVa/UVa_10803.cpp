#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
	double x, y;
	double operator -(const node &rhs)const
	{
		double xdiff=x-rhs.x, ydiff=y-rhs.y;
		return sqrt( xdiff*xdiff + ydiff*ydiff );
	}
} v[102];
double minW[102][102];

int main()
{
	int i, j, k, t, n, cases;
	double newW, ans;
	scanf("%d", &t);
	for( cases=1; cases<=t; cases++ )
	{
		ans=0.0;
		scanf("%d", &n);
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				minW[i][j]=-1;
		for( i=0; i<n; i++ )
			scanf("%lf %lf", &v[i].x, &v[i].y);
		for( i=0; i<n; i++ )
			for( j=i+1; j<n; j++ )
			{
				newW=v[i]-v[j];
				if( newW<=10.0 )
					minW[i][j]=minW[j][i]=newW;
			}
		for( k=0; k<n; k++ )
			for( i=0; i<n; i++ )
				for( j=0; j<n; j++ )
					if( minW[i][k]!=-1 && minW[k][j]!=-1 )
					{
						newW=minW[i][k]+minW[k][j];
						if( newW < minW[i][j] || minW[i][j]==-1 )
							minW[i][j]=minW[j][i]=newW;
					}
		for( i=0; i<n; i++ )
			for( j=i+1; j<n; j++ )
			{
				if( minW[i][j]==-1 )
				{
					ans=-1;
					break;
				}
				if( minW[i][j]>ans )
					ans=minW[i][j];
			}
		printf("Case #%d:\n", cases);
		if( ans==-1 )
			puts("Send Kurdy");
		else
			printf("%.4lf\n", ans);
		putchar('\n');
	}
	return 0;
}
