#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;

// assumes x > y
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
	LL x, y, a, b, g, da, db, mval, na, nb, nval;
	char rev;
	while (scanf("%lld%lld", &x, &y) == 2)
	{
		rev = 0;
		if (x < y) { swap(x, y); rev = 1; }
		g = ex_gcd(x, y, a, b);
		da = y / g; db =-x / g;
		mval = abs(a) + abs(b);
		for (na = a + da, nb = a + db; (nval = abs(na) + abs(nb)) <= mval; na += da, nb += db)
		{
			if (nval < mval)
			{
				mval = nval;
				a = na;
				b = nb;
			}
			else if (nval == mval && a <= b)
			{
				a = na;
				b = nb;
			}
		}
		da = -da; db = -db; // opposite direction
		for (na = a + da, nb = a + db; (nval = abs(na) + abs(nb)) <= mval; na += da, nb += db)
		{
			if (nval < mval)
			{
				mval = nval;
				a = na;
				b = nb;
			}
			else if (nval == mval && a <= b)
			{
				a = na;
				b = nb;
			}
		}
		if (rev) swap(a, b);
		printf("%lld %lld %lld\n", a, b, g);
	}
	return 0;
}