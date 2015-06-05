#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int L = 100002;

void cal_fail(char p[], int len, int f[])
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		j = i - 1;
		while (j > -1 && p[f[j] + 1] != p[i]) j = f[j];
		f[i] = j > -1 ? f[j] + 1 : -1;
	}
}

int kmp(char s[], int slen, char p[], int plen, int f[])
{
	int i, j;
	for (i = 0, j = 0; i < slen; i++)
	{
		while (j > -1 && p[j] != s[i]) j = j ? f[j - 1] + 1 : -1;
		if (i == slen - 1) return j + 1;
		if (++j == plen) j = f[j - 1] + 1;
	}
}

char s[L], r[L];
int len;
int f[L];

int main()
{
	int i, l;
	while (gets(s))
	{
		len = strlen(s);
		for (i = 0; i < len; i++)
			r[i] = s[len - i - 1];
		cal_fail(r, len, f);
		l = kmp(s, len, r, len, f);
		printf("%s", s);
		for (i = len - l - 1; i >= 0; i--) putchar(s[i]);
		puts("");
	}
	return 0;
}