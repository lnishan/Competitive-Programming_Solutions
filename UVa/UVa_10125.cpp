#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
	int n, x, y;
} ab[500000], cd[500000];
int a[1002], abc, cdc;

bool cmp(node a, node b){ return a.n<b.n; }
bool cmp2(node n1, node n2){ return a[n1.y]>a[n2.y]; }

int binSearch(int q)
{
	int l=0, h=abc, m;
	while( h-l>1 )
	{
		m=(l+h)>>1;
		if( ab[m].n<=q )
			l=m;
		else
			h=m;
	}
	return l;
}

inline int input()
{
	char c, n;
	for( c=getchar(); c<48||c>57; c=getchar() ) n=c;
	int x=c-48;
	for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
	return n=='-'?-x:x;
}
int main()
{
	int i, j, n, res;
	while( scanf("%d", &n)==1 && n>0 )
	{
		abc=cdc=0;
		for( i=0; i<n; i++ )
			a[i]=input();
		for( i=0; i<n; i++ )
			for( j=i+1; j<n; j++ )
			{
				ab[abc  ].n=a[i]+a[j];
				ab[abc  ].x=i;
				ab[abc++].y=j;

				cd[++cdc].n=a[j]-a[i];
				cd[  cdc].x=i;
				cd[  cdc].y=j;
			}
		sort(ab, ab+abc, cmp);
		sort(cd, cd+cdc, cmp2);

		for( i=1; i<=cdc; i++ )
		{
			res=binSearch(cd[i].n);
			if( ab[res].n==cd[i].n && ab[res].x!=cd[i].x && ab[res].x!=cd[i].y && ab[res].y!=cd[i].x && ab[res].y!=cd[i].y )
				break;
			
			cd[i].n=-cd[i].n;
			res=binSearch(cd[i].n);
			if( ab[res].n==cd[i].n && ab[res].x!=cd[i].x && ab[res].x!=cd[i].y && ab[res].y!=cd[i].x && ab[res].y!=cd[i].y )
			{
				i=-i;
				break;
			}
		}

		if( i<cdc )
			printf("%d\n", i>0?a[cd[i].y]:a[cd[-i].x] );
		else
			puts("no solution");
	}
	return 0;
}
