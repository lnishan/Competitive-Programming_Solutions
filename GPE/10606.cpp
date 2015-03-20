#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

double r[8], mn, mxr;
bool vst[8];
int n, p[8];

void dfs(int ii)
{
	int i;
	if( ii==n )
	{
		double s=r[p[0]]+r[p[n-1]];
		for( i=1; i<n; i++ )
			s+=2*sqrt(r[p[i]]*r[p[i-1]]);
		mn=min(mn, s);
	}
	for( i=0; i<n; i++ )
		if( !vst[i] )
		{
			p[ii]=i;
			vst[i]=1;
			dfs(ii+1);
			vst[i]=0;
		}
	return ;
}

int main()
{
	int i, t;
	memset(vst, 0, sizeof(vst));
	scanf("%d", &t);
	while( t-- )
	{
		mn=0; mxr=0;
		scanf("%d", &n);
		for( i=0; i<n; i++ )
		{
			scanf("%lf", &r[i]);
			r[i]/=2;
			mxr=max(mxr, r[i]);
			mn+=2*r[i];
		}
		dfs(0);
		printf("%.3lf\n", 2*mxr*mn);
	}
	return 0;
}
