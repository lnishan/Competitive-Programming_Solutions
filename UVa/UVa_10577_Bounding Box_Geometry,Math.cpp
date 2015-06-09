#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = 2 * acos(0);

void rot(double ang, double x, double y, double cx, double cy, double &nx, double &ny)
{
	double co = cos(ang), si = sin(ang);
	double dx = x - cx, dy = y - cy;
	nx = co * dx + (-si) * dy; nx += cx;
	ny = si * dx + co * dy; ny += cy;
}

int main()
{
	int i;
	double x1, y1, x2, y2, x3, y3;
	double m1x, m1y, m2x, m2y, n1x, n1y, n2x, n2y;
	double t, s, cx, cy;
	double ang, nx, ny;
	double min_x, min_y, max_x, max_y;
	int n, tt = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
		n1x = y1 - y2; n1y = x2 - x1;
		n2x = y2 - y3; n2y = x3 - x2;
		m1x = (x1 + x2) / 2.0; m1y = (y1 + y2) / 2.0;
		m2x = (x2 + x3) / 2.0; m2y = (y2 + y3) / 2.0;
		t = n2y * (m2x - m1x) - n2x * (m2y - m1y); t /= n1x * n2y - n1y * n2x;
		s = n1y * (m2x - m1x) - n1x * (m2y - m1y); s /= n1x * n2y - n1y * n2x;
		cx = m1x + n1x * t; cy = m1y + n1y * t;
//		printf("%.3f, %.3f\n", cx, cy);
		
		min_x = min_y = 1e9;
		max_x = max_y = -1e9;
		
		ang = 2.0 * pi / n;
		for (i = 0; i < n; i++)
		{
			rot(ang * i, x1, y1, cx, cy, nx, ny);
			min_x = min(min_x, nx);
			min_y = min(min_y, ny);
			max_x = max(max_x, nx);
			max_y = max(max_y, ny);
		}
		printf("Polygon %d: %.3f\n", ++tt, (max_x - min_x) * (max_y - min_y));
	}
	return 0;
}