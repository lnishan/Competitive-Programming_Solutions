#include <bits/stdc++.h>

using namespace std;

inline int cnt(int n) {
	int ret = 0;
	while (n) {
		++ret;
		n >>= 1;
	}
	return ret;
}

int main() {
	int n, b, p;
	scanf("%d%d%d", &n, &b, &p);
	int ansb = 0, ansp = n * p;
	while (n > 1) {
		ansb += b * (1 << (cnt(n) - 1));
		ansb += (1 << (cnt(n) - 2));
		n -= 1 << (cnt(n) - 2);
	}
	printf("%d %d\n", ansb, ansp);
	return 0;
}
