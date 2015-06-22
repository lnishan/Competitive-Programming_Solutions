#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
	int i, n;
	ll p, x, ai;
	ll mx = 0; int mx_id;
	scanf("%d%lld%lld", &n, &p, &x);
	for (i = 0; i < n; i++, p -= x)
	{
		scanf("%lld", &ai);
		if (p * ai > mx)
		{
			mx = p * ai;
			mx_id = i;
		}
	}
	printf("%d\n", mx_id + 1);
	return 0;
}
