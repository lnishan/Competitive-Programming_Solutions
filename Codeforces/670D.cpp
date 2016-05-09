#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int n;
long long magic;
long long req[N], have[N];

bool can(long long amt) {
	int i;
	long long left = magic;
	for (i = 0; i < n && left >= 0; i++) {
		if (have[i] / req[i] >= amt) continue;
		left -= req[i] * amt - have[i];
	}
	return left >= 0;
}

int main() {
	int i, j, k;
	long long lo, mi, hi;
	scanf("%d%I64d", &n, &magic);
	for (i = 0; i < n; i++)
		scanf("%d", &req[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &have[i]);
	lo = hi = 2e9 + 7;
	for (i = 0; i < n; i++) {
		lo = min(lo, have[i] / req[i]);
		hi = min(hi, (have[i] + magic) / req[i]);
	}
	while (lo < hi) {
		mi = (lo + hi) / 2 + 1;
		if (can(mi))
			lo = mi;
		else
			hi = mi - 1;
	}
	printf("%I64d\n", lo);
	return 0;
}
