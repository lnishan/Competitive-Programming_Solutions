#include <cstdio>
#include <algorithm>
#define MAX 100005
#define INF 1000000001

using namespace std;

int a[MAX], pre[MAX], post[MAX];

int main()
{
	int i, j, n, ans=1;
	scanf("%d", &n);
	
	for( i=1; i<=n; i++ )
		scanf("%d", &a[i]);
	
	//pre
	a[0]=INF;
	pre[0]=0;
	for( i=1; i<=n; i++ )
		if( a[i]>a[i-1] )
			pre[i]=pre[i-1]+1;
		else
			pre[i]=1;
	
	//post
	a[n+1]=-INF;
	post[n+1]=0;
	for( i=n; i>=1; i-- )
		if( a[i]<a[i+1] )
			post[i]=post[i+1]+1;
		else
			post[i]=1;
	
	// ans
	for( i=1; i<=n; i++ )
	{
		ans=max(ans, pre[i]);
		ans=max(ans, post[i]);
		if( a[i+1]-a[i-1]>1 )
			ans=max(ans, pre[i-1]+post[i+1]+1);
		else
		{
			if( a[i]<=a[i-1] )
				ans=max(ans, pre[i-1]+1);
			if( a[i]>=a[i+1] )
				ans=max(ans, post[i+1]+1);
		}
	}
	ans=max(ans, post[2]+1);
	ans=max(ans, pre[n-1]+1);
	
	printf("%d\n", ans);
	return 0;
}
