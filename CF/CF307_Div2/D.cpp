#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull get_comb(ull n, ull M)
{
	int i, j, k;
	ull mat[2][2], tmp[2][2], ans[2][2];
	mat[0][0] = mat[0][1] = mat[1][0] = 1; mat[1][1] = 0;
	ans[0][0] = ans[1][1] = 1; ans[0][1] = ans[1][0] = 0;
	while (n)
	{
		if (n & 1)
		{
			for (i = 0; i < 2; i++)
				for (j = 0; j < 2; j++)
				{
					tmp[i][j] = 0;
					for (k = 0; k < 2; k++)
						tmp[i][j] = (tmp[i][j] + mat[i][k] * ans[k][j]) % M;
				}
			for (i = 0; i < 2; i++)
				for (j = 0; j < 2; j++)
					ans[i][j] = tmp[i][j];
		}
		n >>= 1;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
			{
				tmp[i][j] = 0;
				for (k = 0; k < 2; k++)
					tmp[i][j] = (tmp[i][j] + mat[i][k] * mat[k][j]) % M;
			}
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				mat[i][j] = tmp[i][j];
	}
	return (ans[0][0] + ans[0][1]) % M;
}

ull pow2(ull n, ull M)
{
	ull ret = 1, p = 2;
	while (n)
	{
		if (n & 1)
			ret = (ret * p) % M;
		p = (p * p) % M;
		n >>= 1;
	}
	return ret;
}

int main()
{
	int i;
	ull n, k, M;
	int l;
	ull one, zero, ans;
	scanf("%I64u%I64u%d%I64u", &n, &k, &l, &M);
	if (l != 64 && k >= (1ULL << l))
		puts("0");
	else
	{
		ans = 1;
		zero = get_comb(n, M);
		one = ((pow2(n, M) - zero) + M) % M;
		for (i = 0; i < l; k >>= 1, i++)
			if (k & 1)
				ans = (ans * one) % M;
			else
				ans = (ans * zero) % M;
		printf("%I64u\n", ans % M);
	}
	return 0;
}