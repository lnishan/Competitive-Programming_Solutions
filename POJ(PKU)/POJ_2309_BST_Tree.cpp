#include <cstdio>

using namespace std;

int main()
{
	int t; long long int n;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%I64d", &n);
		printf("%I64d %I64d\n", n-(n & -n)+1, n+(n & -n)-1);
	}
	return 0;
}
