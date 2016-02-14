#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 2;

ll pre[N];
int a[N], n;

inline ll get_sum(int i, int j) {
	return pre[j] - pre[i - 1];
}

double get_ben(int i, int l) {
	return (double)(get_sum(i - l, i) + get_sum(n - l + 1, n)) / (l * 2 + 1) - a[i];
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+1 + n);
	pre[0] = 0;
	for (i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	double ans = -1.0, tmp;
	int ans_mid, ans_len;
	for (i = 1; i <= n; i++) {
		int lo = 0;
		int hi = min(i - 1, n - i);
		while (lo < hi) {
			int m1 = (lo + hi) >> 1;
			int m2 = m1 + 1;
			if (get_ben(i, m1) < get_ben(i, m2))
				lo = m2;
			else
				hi = m1;
		}
		if ((tmp = get_ben(i, lo)) > ans) {
			ans = tmp;
			ans_mid = i;
			ans_len = lo;
		}
	}
	printf("%d\n", ans_len * 2 + 1);
	for (i = 0; i < ans_len; i++) printf("%d ", a[ans_mid - ans_len + i]);
	printf("%d ", a[ans_mid]);
	for (i = 0; i < ans_len; i++) printf("%d ", a[n - ans_len + 1 + i]);
	return 0;
}
