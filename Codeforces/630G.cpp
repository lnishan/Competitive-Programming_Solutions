#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const int N = 555;

ull c[N][N];

ull getc(int n, int m) {
	if (m == 0 || n == m) return 1;
	ull &cur = c[n][m];
	if (cur) return cur;
	return cur = getc(n - 1, m - 1) + getc(n - 1, m);
}

int main() {
	int n;
	cin >> n;
	cout << getc(n + 4, 5) * getc(n + 2, 3) << "\n";
	return 0;
}
