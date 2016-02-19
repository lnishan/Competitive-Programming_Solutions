#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 2;

int n, p;
pii a[N];

double notprob(int i) {
	return 1.0 - (double)((a[i].second / p) - ((a[i].first - 1) / p)) / (a[i].second - a[i].first + 1);
}

int main() {
	int i;
	scanf("%d%d", &n, &p);
	for (i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
	double ans = 1000.0 * (1 - notprob(n - 1) * notprob(0));
	for (i = 0; i < n - 1; i++)
		ans += 1000.0 * (1 - notprob(i) * notprob(i + 1));
	printf("%.17f\n", ans * 2.0);
	return 0;
}
