#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull fib[52];

int main()
{
	int i, j, k, n;
	ull kth;
	fib[0] = fib[1] = 1;
	for (i = 2; i <= 50; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	scanf("%d%I64u", &n, &kth);
	for (i = n, k = 1; i >= 1; )
		if (kth <= fib[i - 1])
		{
			printf("%d ", k);
			++k;
			--i;
		}
		else
		{
			printf("%d %d ", k + 1, k);
			kth -= fib[i - 1];
			k += 2;
			i -= 2;
		}
	return 0;
}