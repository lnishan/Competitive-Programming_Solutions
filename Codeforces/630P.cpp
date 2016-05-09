#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

int main() {
	long double th, n, r;
	double ntmp, rtmp;
	cin >> ntmp >> rtmp;
	n = ntmp;
	r = rtmp;
	// long double ans = 0.5 * r * r * sqrt((1 - cos(2 * th)) / (1 - cos(3 * th))) * sin(0.5 * th) * n * 2;
	// long double ans = n * r * r * sqrt(sin(0.5 * PI / n) * sin(0.5 * PI / n) * (1 - cos(2 * PI / n)) / (1 - cos(3 * PI / n)));
	long double ans = n * r * r * sin(PI / n) * sin(0.5 * PI / n) / sin(1.5 * PI / n);

	printf("%.17f\n", (double)ans);
	return 0;
}
