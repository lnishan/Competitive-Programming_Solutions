#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double ans = a * a * a * sqrt(2.0) / 12;
	ans += b * b * b * sqrt(2.0) / 6;
	double x2 = c * c / (2.0 * (1 - cos(2 * PI / 5)));
	ans += x2 * 2.5 * sin(2 * PI / 5) * sqrt(c * c - x2) / 3;
	printf("%.17f\n", ans);
	return 0;
}
