#include <cstdio>
#include <cmath>

using namespace std;

struct node
{
	double x, y;
	double operator -(const node &b)const
	{
		return sqrt( (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y) ) + 16;
	}
} a[8], p[8], ansp[8];
double ans;
char v[8]={0};
int n;

void DFS(int i)
{
	int j;
	if( i==n )
	{
		double tmp=0.0;
		for( j=1; j<n; j++ )
			tmp+=p[j]-p[j-1];
		if( tmp<ans )
		{
			for( j=0; j<n; j++ )
				ansp[j]=p[j];
			ans=tmp;
		}
		return ;
	}
	else
	{
		for( j=0; j<n; j++ )
			if( !v[j] )
			{
				v[j]=1;
				p[i].x=a[j].x;
				p[i].y=a[j].y;
				DFS(i+1);
				v[j]=0;
			}
	}
	return ;
}

int main()
{
	int i, cases=0;
	while( scanf("%d", &n)==1 && n>0 )
	{
		ans=100000.0;
		for( i=0; i<n; i++ )
			scanf("%lf %lf", &a[i].x, &a[i].y);
		DFS(0);
		puts("**********************************************************");
		printf("Network #%d\n", ++cases);
		for( i=1; i<n; i++ )
			printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n", ansp[i-1].x, ansp[i-1].y, ansp[i].x, ansp[i].y, ansp[i]-ansp[i-1]);
		printf("Number of feet of cable required is %.2lf.\n", ans);
	}
	return 0;
}
