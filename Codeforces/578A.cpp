#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	if (x < y)
		puts("-1");
	else if (x == y)
		printf("%d\n", x);
	else
		printf("%.17f\n", min(
					(double)(x + y) / ((x + y) / (2 * y)) * 0.5
					, x - y < 2 * y ? 2e9 : (double)(x - y) / ((x - y) / (2 * y)) * 0.5 ));
	return 0;
}
