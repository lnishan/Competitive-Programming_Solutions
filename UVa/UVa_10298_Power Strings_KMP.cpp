#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int L = 1000002;

void cal_failure(char s[], int len, int f[])
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		j = i - 1;
		while (j >= 0 && s[f[j] + 1] != s[i]) j = f[j];
		f[i] = j >= 0 ? f[j] + 1 : -1;
	}
}

/*
int kmp(char s[], int len, int f[])
{
	int i, j = 0;
	for (i = 1; i < len; )
	{
		while (i < len && s[i] == s[j]) { i++; j++; }
		if (i == len) return len - j;
		while (j >= 1 && s[f[j - 1] + 1] != s[i]) j = f[j - 1] + 1;
		if (j == 0) i++;
	}
	return len;
}*/

char s[L];
int f[L];

int main()
{
	int i, len, ret;
	while (gets(s) && s[0] != '.')
	{
		len = strlen(s);
		if (len == 0) continue;
		cal_failure(s, len, f);
//		for (i = 0; i < len; i++)
//			printf("%d ", f[i]);
//		puts("");
		printf("%d\n", len / (len - f[len - 1] - 1));
	}
	return 0;
} 