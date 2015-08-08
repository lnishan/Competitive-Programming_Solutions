#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void cal_f(char p[], int len, int f[])
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		j = i - 1;
		while (j > -1 && p[f[j] + 1] != p[i]) j = f[j];
		f[i] = j > -1 ? f[j] + 1 : -1;
	}
}

int kmp(char s[], int sl, char p[], int pl, int f[], int st)
{
	int i, j;
	for (i = st, j = 0; i < sl; i++)
	{
		while (j > -1 && s[i] != p[j]) j = j ? f[j - 1] + 1 : -1;
		if (++j == pl)
			return i - pl + 1;
	}
	return -1;
}

const int L = 400005;

char s[L], r[L];
int f[L];

int main()
{
	int i, t, l;
	int ret;
	char palin;
	scanf("%d", &t); gets(s);
	while (t--)
	{
		palin = 1;
		gets(s);
		l = strlen(s);
		for (i = 0; i < l; i++)
		{
			s[l + i] = s[i];
			r[i] = s[l - i - 1];
			if (r[i] != s[i]) palin = 0;
		}
//		s[l << 1] = '\0';
//		puts(s);
//		r[l] = '\0';
//		puts(r);
		cal_f(r, l, f);
		ret = kmp(s, l << 1, r, l, f, 1);
//		cout << ret << endl;
		if (ret > 0 && ret < l)
			puts("alindrome");
		else if (palin)
			puts("palindrome");
		else
			puts("simple");
	}
	return 0;
}