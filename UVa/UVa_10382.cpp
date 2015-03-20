#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct node
{
	double l, r;
	bool operator <(const node &b)const
	{
		return r<b.r;
	}
} a[10000];
int n, l, w;

int main()
{
	int i, j, p, r, ans;
	double tmp, cur, mxr;
	while( scanf("%d%d%d", &n, &l, &w)==3 )
	{
		ans=0;
		for( i=0; i<n; i++ )
		{
			scanf("%d%d", &p, &r);
			tmp=sqrt(r*r-double(w*w)/4);
			a[i].l=p-tmp;
		 	a[i].r=p+tmp;
		}
		sort(a, a+n);
		cur=0;
		for( i=0; i<n; i++ )
		{
			mxr=-1;
			for( j=i; j<n; j++ )
				if( a[j].l<=cur )
					mxr=max(mxr, a[j].r);
		 		else
					break;
			if( mxr==-1 ) break;
			cur=mxr;
			ans++;
			i=j-1;
		}
		if( cur>=l )
			printf("%d\n", ans);
		else
			puts("-1");
	}
	return 0;
}
