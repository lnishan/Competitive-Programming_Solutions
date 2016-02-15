#include <bits/stdc++.h>

using namespace std;

double a[20];
const char *expr[] = {
	"x^y^z",
	"x^z^y",
	"(x^y)^z",
	"(x^z)^y",
	"y^x^z",
	"y^z^x",
	"(y^x)^z",
	"(y^z)^x",
	"z^x^y",
	"z^y^x",
	"(z^x)^y",
	"(z^y)^x" };

char invalid[20];

int main() {
	double x, y, z;
	int i; double mx; int mxi;
	scanf("%lf%lf%lf", &x, &y, &z);
	a[0] = z * log(y) + log(log(x));
	a[1] = y * log(z) + log(log(x));
	a[2] = log(z) + log(y) + log(log(x));
	a[3] = log(z) + log(y) + log(log(x));
	a[4] = z * log(x) + log(log(y));
	a[5] = x * log(z) + log(log(y));
	a[6] = log(x) + log(z) + log(log(y));
	a[7] = log(x) + log(z) + log(log(y));
	a[8] = y * log(x) + log(log(z));
	a[9] = x * log(y) + log(log(z));
	a[10] = log(x) + log(y) + log(log(z));
	a[11] = log(x) + log(y) + log(log(z));
	if (x < 1.0) for (i = 0; i < 4; i++) invalid[i] = 1;
	if (y < 1.0) for (i = 4; i < 8; i++) invalid[i] = 1;
	if (z < 1.0) for (i = 8; i < 12; i++) invalid[i] = 1;
	for (i = 0; i < 12; i++) if (!invalid[i]) break;
	if (i == 12) {
		a[2] = z * y * log(x);
		a[6] = x * z * log(y);
		a[10] = x * y * log(z);
		if (a[2] >= a[6] && a[2] >= a[10])
			printf("%s\n", expr[2]);
		else if (a[6] >= a[2] && a[6] >= a[10])
			printf("%s\n", expr[6]);
		else
			printf("%s\n", expr[10]);
	} else {
		mx = a[i]; mxi = i;
		for ( ; i < 12; i++)
			if (a[i] > mx) {
				mx = a[i];
				mxi = i;
			}
		printf("%s\n", expr[mxi]);
	}
	return 0;
}
