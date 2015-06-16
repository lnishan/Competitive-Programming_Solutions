#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define N(X) (X - '0')

using namespace std;

char s[105];

int main()
{
	int i, j, k, l, ans;
	char flag = 0;
	gets(s);
	l = strlen(s);
	for (i = l - 1; i >= 0; i--)
		s[i + 2] = s[i];
	s[0] = s[1] = '0';
	l += 2;
	for (i = 0; i < l && !flag; i++)
		for (j = i + 1; j < l && !flag; j++)
			for (k = j + 1; k < l && !flag; k++)
				if ((N(s[i]) * 100 + N(s[j]) * 10 + N(s[k])) % 8 == 0)
					flag = 1;
	if (flag)
	{
		puts("YES");
		ans = s[i - 1] - '0';
		ans = ans * 10 + s[j - 1] - '0';
		ans = ans * 10 + s[k - 1] - '0';
		printf("%d", ans);
	}
	else
		puts("NO");
	return 0;
}