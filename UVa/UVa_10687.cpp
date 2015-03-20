#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 2147483647

using namespace std;

struct node
{
	int i, x, y;
	int operator -(const node &b)const
	{
		return (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y);
	}
	bool operator <(const node &b)const
	{
		if( x != b.x )
			return x < b.x;
		else
			return y < b.y;
	}
} a[1000];
int n;
char v[1002];

void dfs(int i)
{
	int j, d, mn=INF, mn2=INF, m1, m2;
	for( j=0; j<n; j++ )
		if( i!=j )
		{
			d=a[j]-a[i];
			if( d<mn )
			{
				m2=m1;
				m1=j;
				mn2=mn;
				mn=d;
			}
			else if( d<mn2 )
			{
				mn2=d;
				m2=j;
			}
		}
	if( mn!=INF && !v[m1] )
	{
		v[m1]=1;
		dfs(m1);
	}
	if( mn2!=INF && !v[m2] )
	{
		v[m2]=1;
		dfs(m2);
	}
	return ;
}

int main()
{
	int i, j, si;
	while( scanf("%d", &n)==1 && n>0 )
	{
		memset(v, 0, sizeof(v));
		for( i=0; i<n; i++ )
		{
			a[i].i=i;
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		sort(a, a+n);
		for( i=0; i<n; i++ )
			if( a[i].i==0 )
			{
				si=i;
				break;
			}
		v[si]=1;
		dfs(si);
		for( i=0; i<n; i++ )
			if( !v[i] ) break;
		if( i==n )
			puts("All stations are reachable.");
		else
			puts("There are stations that are unreachable.");
	}
	return 0;
}
