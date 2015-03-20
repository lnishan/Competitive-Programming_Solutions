#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

inline int getVal(char &c)
{
	if (isdigit(c))
		return c-'0';
	else if (isupper(c))
		return c-'A'+10;
	else if (islower(c))
		return c-'a'+36;
	return 0;
}

char s[10002];
int main()
{
	int i, mx, l, tot;
	while (gets(s))
	{
		tot = 0;
		mx = 1;
		l = strlen(s);
		for (i = 0; i < l; i++)
		{
			tot += getVal(s[i]);
			mx = max(mx, getVal(s[i]));
		}
		for (i = mx+1; i <= 62; i++)
			if (tot % (i-1) == 0)
				break;
		if (i > 62)
			puts("such number is impossible!");
		else
			printf("%d\n", i);
	}
	return 0;
}
