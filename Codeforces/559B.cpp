#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int L = 200005;

char s1[L], s2[L];

bool cp(int l1, int r1, int l2, int r2)
{
	int i, j;
	if ((r1 - l1 + 1) & 1)
	{
		for (i = l1, j = l2; i <= r1 && j <= r2; i++, j++)
			if (s1[i] != s2[j])
				return false;
		return true;
	}
	else
	{
		int m1 = (l1 + r1) >> 1;
		int m2 = (l2 + r2) >> 1;
		return (cp(l1, m1, m2 + 1, r2)
				&& cp(m1 + 1, r1, l2, m2))
				||
				(cp(l1, m1, l2, m2)
				&& cp(m1 + 1, r1, m2 + 1, r2));
	}
}

int main()
{
	int l1, l2;
	gets(s1); l1 = strlen(s1);
	gets(s2); l2 = strlen(s2);
	puts(cp(0, l1 - 1, 0, l2 - 1) ? "YES" : "NO");
	return 0;
}