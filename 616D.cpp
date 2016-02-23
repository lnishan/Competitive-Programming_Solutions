#include <cstdio>

using namespace std;

const int N = 5e5 + 2;
const int M = 1e6 + 2;

int a[N];
int cnt[M];

inline int input() {
	char c;
	for (c = getchar(); c < 48 || c > 57; c = getchar()) ;
	int x = c - 48;
	for (c = getchar(); c > 47 && c < 58; c = getchar()) x = x * 10 + c - 48;
	return x;
}

int main() {
	int i, j, n, k, dist = 0;
	int l, r, ans, ansl, ansr;
	n = input(); k = input();
	for (i = 0; i < n; i++) a[i] = input();
	for (r = 0; r < n && dist <= k; r++) {
		if (!cnt[a[r]]) ++dist;
		++cnt[a[r]];
	}
	if (dist > k) {
		--dist;
		--cnt[a[r - 1]];
		--r;
	}
	l = 0;
	ans = r; ansl = l; ansr = r - 1;
	while (r < n) {
		// fprintf(stderr, " %d %d, dist = %d\n", l, r, dist);
		for ( ; r < n && dist <= k + 1; r++) {
			if (!cnt[a[r]]) ++dist;
			++cnt[a[r]];
		}
		if (dist > k + 1) {
			--dist;
			--cnt[a[r - 1]];
			--r;
		}
		for ( ; l < r && dist > k; l++) {
			--cnt[a[l]];
			if (!cnt[a[l]]) --dist;
		}
		if (r - l > ans) {
			ans = r - l;
			ansl = l;
			ansr = r - 1;
		}
	}
	printf("%d %d\n", ansl + 1, ansr + 1);
	return 0;
}
