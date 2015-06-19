#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll ten[12];

int main()
{
	int i, j;
	ll n, ans = 0;
	ten[0] = 1;
	for (i = 1; i <= 10; i++)
		ten[i] = ten[i - 1] * 10;
	scanf("%I64d", &n);
	for (i = 0; i < 10 && n >= ten[i + 1]; i++)
		ans += ten[i] * 9 * (i + 1);
	ans += (n - ten[i] + 1) * (i + 1);
	printf("%I64d\n", ans);
//	while (1);
	return 0;
}