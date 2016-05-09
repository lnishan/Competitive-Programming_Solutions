#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

char s[N];

int main() {
	int i, n, k;
	scanf("%d%d", &n, &k);
	scanf(" ");
	gets(s);
	int md = 0;
	for (i = 0; i < n; i++) {
		int tmd = max(s[i] - 'a', 'z' - s[i]);
		md += tmd;
	}
	if (md < k)
		puts("-1");
	else {
		int rem = k;
		for (i = 0; i < n; i++) {
			if (s[i] - 'a' > 'z' - s[i]) {
				int ch = min((int)s[i] - 'a', rem);
				putchar(s[i] - ch);
				rem -= ch;
			} else {
				int ch = min('z' - (int)s[i], rem);
				putchar(s[i] + ch);
				rem -= ch;
			}
		}
		puts("");
	}
	return 0;
}
