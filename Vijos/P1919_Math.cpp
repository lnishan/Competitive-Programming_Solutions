#include <cstdio>

using namespace std;

double ipow(const double &x, const int &n)
{
	if (!n) return 1.0f;
	double h = ipow(x, n >> 1);
	return h * h * ( n & 1 ? x : 1 );
}

int main()
{
	int i, m, n;
	double ans;
	scanf("%d%d", &m, &n);
	ans = m;
	for (i = m - 1; i >= 1; i--)
		ans -= ipow(double(i) / m, n);
	printf("%.4f\n", ans);
	return 0;
}
