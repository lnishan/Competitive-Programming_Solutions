#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	printf("%d\n", (a + b + c) * (a + b + c) - a * a - c * c - e * e);
	return 0;
}