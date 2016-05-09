#include <bits/stdc++.h>

using namespace std;

char s[(int)3e5 + 5];

int main() {
	long long ans = 0;
	gets(s);
	int i, l = strlen(s);
	if ((s[0] - '0') % 4 == 0) ans++;
	for (i = 1; i < l; i++) {
		if (((s[i - 1] - '0') * 10 + s[i] - '0') % 4 == 0)
			ans += i;
		if ((s[i] - '0') % 4 == 0)
			ans++;
	}
	printf("%I64d\n", ans);
	return 0;
}
