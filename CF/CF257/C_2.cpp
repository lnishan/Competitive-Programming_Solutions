#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long int getL(int L, int portionCnt)
{
	return floor( double(L) / portionCnt );
}

int main()
{
	long long int n, m, k, ans=0;
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	
	if ( n-1 + m-1 < k )
		puts("-1");
	else
	{
		if ( k + 1 <= n )
			ans = max(ans, getL(n, k+1) * m);
		if ( k + 1 <= m )
			ans = max(ans, getL(m, k+1) * n);
		if ( k + 1 > n && k + 1 > m )
		{
			ans = max(ans, getL(n, k - (m-1) + 1) * 1);
			ans = max(ans, getL(m, k - (n-1) + 1) * 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
