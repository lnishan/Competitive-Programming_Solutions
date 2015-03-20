#include <cstdio>
#include <algorithm>

using namespace std;

long long int a[100002], s[100002], sr[100002];

int main()
{
	int i, n, m, t, l, r;
	s[0]=sr[0]=0;
	scanf("%d", &n);
	for( i=1; i<=n; i++ )
	{
		scanf("%I64d", &a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1, a+1+n);
	for( i=1; i<=n; i++ )
		sr[i]=sr[i-1]+a[i];
	scanf("%d", &m);
	while( m-- )
	{
		scanf("%d%d%d", &t, &l, &r);
		if( t==1 )
			printf("%I64d\n", s[r]-s[l-1]);
		else
			printf("%I64d\n", sr[r]-sr[l-1]);
	}
	return 0;
}
