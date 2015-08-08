#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 10002;
const int RES = 1e6;
long long f[N];

void pre()
{
	int i;
	f[1] = 1;
	for (i = 2; i < N; i++)
	{
		f[i] = f[i - 1] * i;
		while (f[i] % 10 == 0) f[i] /= 10;
		f[i] = f[i] % RES;
	}
	for (i = 2; i < N; i++)
		f[i] %= 10;
}

int main()
{
	int n;
	pre();
	while (scanf("%d", &n) == 1)
		printf("%5d -> %d\n", n, f[n]);
	return 0;

}