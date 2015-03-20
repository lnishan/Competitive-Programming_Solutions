// where is ur inQ XD?
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define MAX_V 202
#define INF 1000000

using namespace std;

double cord[MAX_V][2], dist[MAX_V][MAX_V], w[MAX_V];
queue<int> q;

int main()
{
	int i, j, k, n, x, y, qi, cases=0;
	double maxW;
	while( scanf("%d", &n)==1 && n>0 )
	{
		while( !q.empty() )
			q.pop();
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				dist[i][j]=INF;
		for( i=0; i<n; i++ )
			w[i]=INF;
		for( i=0; i<n; i++ )
			scanf("%lf%lf", &cord[i][0], &cord[i][1]);
		for( i=0; i<n; i++ )
			for( j=i+1; j<n; j++ )
			{
				double xdiff=cord[i][0] - cord[j][0], ydiff=cord[i][1] - cord[j][1];
				dist[i][j]=dist[j][i]=sqrt(xdiff*xdiff + ydiff*ydiff);
			}
		q.push(0); w[0]=0;
		while( !q.empty() )
		{
			qi=q.front();
			for( i=0; i<n; i++ )
			{
				maxW = max( w[qi], dist[qi][i] );
				if( maxW < w[i] )
				{
					w[i]= maxW;
					q.push(i);
				}
			}
			q.pop();
		}
		printf("Scenario #%d\n", ++cases);
		printf("Frog Distance = %.3lf\n\n", w[1]);
	}
	return 0;
}
