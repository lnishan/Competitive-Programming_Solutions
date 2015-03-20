#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int a[30002], g[30002];
priority_queue<int, vector<int>, greater<int> > mnq;
priority_queue<int> mxq;

int main()
{
	int i, j, m, n, p, tmp;
	memset(g, 0, sizeof(g));
	scanf("%d%d", &m, &n);
	for( i=1; i<=m; i++ )
		scanf("%d", &a[i]);
	for( i=0; i<n; i++ )
	{
		scanf("%d", &p);
		g[p]++;
	}
	for( i=1; i<=m; i++ )
	{
		mnq.push(a[i]);
		if( mnq.top()==a[i] && mxq.size()>0 )
			if( a[i]<mxq.top() )
			{
				tmp=mxq.top();
				mxq.pop();
				mxq.push(a[i]);
				mnq.pop();
				mnq.push(tmp);
			}
		for( j=0; j<g[i]; j++ )
		{
			printf("%d\n", mnq.top());
			mxq.push(mnq.top());
			mnq.pop();
		}
	}
	//while(1);
	return 0;
}
