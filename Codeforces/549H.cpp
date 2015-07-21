#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define EPS 1e-10

using namespace std;

double get_max(double a, double b, double v)
{
	double ret;
	if (a >= 0.0)
	{
		if (b >= 0.0)
			return (a + v) * (b + v);
		else
		{
			ret = ((a - v <= 0.0) ? 0.0 : a - v) * ((b + v >= 0.0) ? 0.0 : b + v);
			ret = max(ret, (a + v) * (b + v));
			ret = max(ret, (a - v) * (b - v));
			return ret;
		}
	}
	else
	{
		if (b >= 0.0)
		{
			ret = ((a + v >= 0.0) ? 0.0 : a + v) * ((b - v <= 0.0) ? 0.0 : b - v);
			ret = max(ret, (a + v) * (b + v));
			ret = max(ret, (a - v) * (b - v));
			return ret;
		}
		else
			return (a - v) * (b - v);
	}
}

double get_min(double a, double b, double v)
{
	double ret;
	if (a >= 0.0)
	{
		if (b >= 0.0)
		{
			ret = ((a - v <= 0.0) ? 0.0 : a - v) * ((b - v <= 0.0) ? 0.0 : b - v);
			ret = min(ret, (a - v) * (b + v));
			ret = min(ret, (a + v) * (b - v));
			return ret;
		}
		else
			return (a + v) * (b - v);
	}
	else
	{
		if (b >= 0.0) // - +
			return (a - v) * (b + v);
		else
		{
			ret = ((a + v >= 0.0) ? 0.0 : a + v) * ((b + v >= 0.0) ? 0.0 : b + v);
			ret = min(ret, (a + v) * (b - v));
			ret = min(ret, (a - v) * (b + v));
			return ret;
		}
	}
}

int main()
{
	// freopen("debug.txt", "w", stdout);
	double l = 0.0, m, h;
	double a, b, c, d, max1, min1, max2, min2;
	int it = 0;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	h = abs(a); h = max(h, abs(b)); h = max(h, abs(c)); h = max(h, abs(d));
	unsigned long long lmt = log2( (h - l) * 1e10 ) + 2;
	while (h - l > EPS)
	{
		m = (l + h) * 0.5;
		// can(m) ?
		min1 = get_min(a, d, m); max1 = get_max(a, d, m);
		min2 = get_min(b, c, m); max2 = get_max(b, c, m);
		if (min1 > min2) { swap(min1, min2); swap(max1, max2); }
		if (min2 <= max1) // overlap -> can
			h = m;
		else
			l = m + EPS;
		if (++it >= lmt) break;
	}
	printf("%.10f\n", h);
	return 0;
}
