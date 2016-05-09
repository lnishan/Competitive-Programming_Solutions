#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull pw(int n, int p) {
	ull tmp = n, ret = 1;
	while (p) {
		if (p & 1)
			ret *= tmp;
		p >>= 1;
		tmp *= tmp;
	}
	return ret;
}

int main() {
	int i, j, k, n, m;
	cin >> n;
	m = 2 * (n - 1);
	ull ans = 3 * pw(4, m - n - 1) * 2;
	for (i = 1; i < m - n; i++)
		ans += 3 * 3 * pw(4, m - n - 2);
	cout << ans * 4;
	return 0;
}
