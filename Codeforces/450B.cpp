#include <cstdio>

using namespace std;

const int MOD_N = 1000000007;

class mat
{
public:
	long long int m[2][2];
	mat(long long int a11, long long int a12, long long int a21, long long int a22)
	{
		m[0][0] = a11;
		m[0][1] = a12;
		m[1][0] = a21;
		m[1][1] = a22;
	}
	mat operator * (const mat &rhs)const
	{
		int i, j, k;
		long long int newm[2][2];
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
			{
				newm[i][j] = 0;
				for (k = 0; k < 2; k++)
					newm[i][j] = ( newm[i][j] + m[i][k] * rhs.m[k][j] ) % MOD_N;
			}
		mat tmp(newm[0][0], newm[0][1], newm[1][0], newm[1][1]);
		return tmp;
	}
} T(0, 1, -1, 1);

mat getPower(int p)
{
	if (p == 1)
		return T;
	mat tmp=getPower(p>>1);
	tmp = tmp * tmp;
	if (p % 2)
		tmp = tmp * T;
	return tmp;
}

int main()
{
	int i, j;
	long long int x, y, n, ans;
	/*
	mat tmp = getPower(3);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", tmp.m[i][j]);
		puts("");
	}*/
	scanf("%I64d%I64d", &x, &y);
	scanf("%I64d", &n);
	if (n == 1)
		ans = x % MOD_N;
	else if (n == 2)
		ans = y % MOD_N;
	else
	{
		mat tmp=getPower(n-2);
		ans = (tmp.m[1][0]*x + tmp.m[1][1]*y) % MOD_N;
	}
	while (ans < 0)
		ans += MOD_N;
	printf("%I64d\n", ans);
	return 0;
	
}
