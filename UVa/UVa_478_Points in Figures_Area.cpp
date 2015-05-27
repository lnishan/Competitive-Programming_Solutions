#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define ep (1e-9)

using namespace std;

const int N = 102;
const int L = 1002;

struct fig
{
	char type;
	union
	{
		struct { double x[3], y[3]; };
		struct { double cx, cy, r; };
	};
} a[N];
char s[L];

double area_tri(double x[], double y[])
{
	int i, j;
	double ret = 0;
	for (i = 0; i < 3; i++)
		ret += x[i] * y[ (i + 1) % 3 ] - x[ (i + 1) % 3 ] * y[i];
	return abs(ret) / 2.0f;
}

double area_tri(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double x[] = {x1, x2, x3};
	double y[] = {y1, y2, y3};
	return area_tri(x, y);
}

inline bool equal(const double &a, const double &b)
{
	return abs(a - b) <= ep;
}

int main()
{
	int i, j, it = 0, itP = 0;
	char type, yes, cont;
	double x, y;
	while (gets(s) && s[0] != '*')
	{
		++it;
		switch (s[0])
		{
			case 'r':
				sscanf(s, "%c %lf %lf %lf %lf", &a[it].type, &a[it].x[0], &a[it].y[0], &a[it].x[1], &a[it].y[1]);
				break;
			case 'c':
				sscanf(s, "%c %lf %lf %lf", &a[it].type, &a[it].cx, &a[it].cy, &a[it].r);
				break;
			case 't':
				sscanf(s, "%c %lf %lf %lf %lf %lf %lf", &a[it].type, &a[it].x[0], &a[it].y[0], &a[it].x[1], &a[it].y[1], &a[it].x[2], &a[it].y[2]);
				break;
		}
	}
	while (scanf("%lf %lf", &x, &y) == 2 && !(equal(x, 9999.9) && equal(y, 9999.9)))
	{
		++itP;
		cont = 0;
		for (i = 1; i <= it; i++)
		{
			yes = 0;
			switch (a[i].type)
			{
				case 'r':
					if ( a[i].x[0] < x && x < a[i].x[1] && a[i].y[0] > y && y > a[i].y[1] )
						yes = 1;
					break;
				case 'c':
					if ( (x - a[i].cx) * (x - a[i].cx) + (y - a[i].cy) * (y - a[i].cy) < a[i].r * a[i].r )
						yes = 1;
					break;
				case 't':
					double a1 = area_tri(a[i].x, a[i].y);
					double a2_1 = area_tri(a[i].x[0], a[i].y[0], a[i].x[1], a[i].y[1], x, y);
					double a2_2 = area_tri(a[i].x[1], a[i].y[1], a[i].x[2], a[i].y[2], x, y);
					double a2_3 = area_tri(a[i].x[2], a[i].y[2], a[i].x[0], a[i].y[0], x, y);
					double a2 = a2_1 + a2_2 + a2_3;
					if (equal(a1, a2) && !equal(a2_1, 0.0) && !equal(a2_2, 0.0) && !equal(a2_3, 0.0))
						yes = 1;
					break;
			}
			if (yes)
			{
				cont = 1;
				printf("Point %d is contained in figure %d\n", itP, i);
			}
		}
		if (!cont)
			printf("Point %d is not contained in any figure\n", itP);
	}
	return 0;
}
