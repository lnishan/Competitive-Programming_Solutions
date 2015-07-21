#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int L = 22;

char av[L][30];
char s[L];

int main()
{
	int i, j, k, l, ans = 0;
	gets(s); l = strlen(s);
	for (i = 0; i <= l; i++)
		fill(av[i], av[i] + 26, 1);
	for (i = 0; i <= l; i++)
	{
		for (j = k = 0; j < 26; j++)
			if (av[i][j]) ++k;
		ans += k;
		for (j = i + 1; j <= l && s[j - 1] == s[i]; j++)
			av[j][s[i] - 'a'] = 0;
	}
	printf("%d\n", ans);
	return 0;
}