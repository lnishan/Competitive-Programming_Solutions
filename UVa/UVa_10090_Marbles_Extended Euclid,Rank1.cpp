#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;

inline LL input()
{
	char c;
	for (c = getchar(); c < 48 || c > 57; c = getchar() ) ;
	LL x = c - 48;
	for (c = getchar(); c > 47 && c < 58; c = getchar() ) x = x * 10 + c - 48;
	return x;
}

// x > y
LL ex_gcd(LL x, LL y, LL &a, LL &b)
{
	if (y == 0)
	{
		a = 1;
		b = 0;
		return x;
	}
	LL c, d, g = ex_gcd(y, x % y, d, c);
	a = c;
	b = d - x / y * c;
	return g;
}

int main()
{
	LL n, cx, cy, x, y, g, a, b, da, db, mul;
	LL c, mc, ma, mb;
	while ((n = input()) && n)
	{
		cx = input(); x = input();
		cy = input(); y = input();
		g = ex_gcd(x, y, a, b);
		if (n % g) { puts("failed"); continue; }
		a *= n / g; b *= n / g;
		da = y / g; db =-x / g;
		if (a <= 0)
		{
			if (da < 0) { da = -da; db = -db; }
			mul = ((-a) - 1) / da + 1;
		}
		else // if (b <= 0)
		{
			if (db < 0) { da = -da; db = -db; }
			mul = ((-b) - 1) / db + 1;
		}
		a += da * mul;
		b += db * mul;
		if (a < 0 || b < 0)
			puts("failed");
		else
		{
			c = a * cx + b * cy;
			mc = c; ma = a; mb = b;
			if (da < 0)
				mul = a / (-da);
			else
				mul = b / (-db);
			a += da * mul; b += db * mul;
			c = a * cx + b * cy;
			if (c < mc) { mc = c; ma = a; mb = b; }
			printf("%lld %lld\n", ma, mb);
			
		}
	}
	return 0;
}