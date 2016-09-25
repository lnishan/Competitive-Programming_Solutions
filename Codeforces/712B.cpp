#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int cnt[2];
char s[N];

int main() {
	int i, j;
	gets(s);
	for (i = 0; s[i]; ++i) {
		if (s[i] == 'L')
			--cnt[0];
		else if (s[i] == 'R')
			++cnt[0];
		else if (s[i] == 'D')
			--cnt[1];
		else
			++cnt[1];
	}
	cnt[0] = abs(cnt[0]);
	cnt[1] = abs(cnt[1]);
	if ((cnt[0] + cnt[1]) & 1)
		puts("-1");
	else
		printf("%d\n", min(cnt[0], cnt[1]) + abs(cnt[1] - cnt[0]) / 2);
	return 0;
}
