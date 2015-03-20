#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	int i, n, a, b;
	long long int ans=0;
	while( scanf("%d", &n)==1 && n>0 )
	{
		ans=0;
		while( !pq.empty() )
			pq.pop();
		for( i=0; i<n; i++ )
		{
			scanf("%d", &a);
			pq.push(a);
		}
		for( i=1; i<n; i++ )
		{
			a=pq.top();
			pq.pop();
			b=pq.top();
			pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
