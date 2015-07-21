#include <cstdio>
#include <cstring>

using namespace std;

char s[200010];
char fl[100005];
char ffl[100005];

int main()
{
	int i, j, l, m, p;
	char f = 0;
	gets(s);
	l = strlen(s);
	for (i = l; i >= 1; i--)
		s[i] = s[i-1];
	for (i = 1; i <= l/2 + 1; i++)
		fl[i] = 0;
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &p);
		if (p > l / 2)
			p = l - p + 1;
		fl[p] ^= 1;
	}
	for (i = 1; i <= l; i++)
	{
		if (i <= l/2)
		{
			f ^= fl[ i ];
			ffl[i] = f;
			if (f)
				putchar(s[l - i + 1]);
			else
				putchar(s[i]);
		}
		else
		{
			if (ffl[l - i + 1])
				putchar(s[l - i + 1]);
			else
				putchar(s[i]);
		}
	}
	return 0;
}
