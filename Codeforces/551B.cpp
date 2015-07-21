#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100005;

long long ca[30], cb[30], cc[30];
char sa[N], sb[N], sc[N];

int main()
{
	int i, j;
	long long la, lb, lc;
	long long T, B, C, ansT = -1, ansB, ansC;
	double minC = 1e9, tC;
	fill(ca, ca + 30, 0);
	fill(cb, cb + 30, 0);
	fill(cc, cc + 30, 0);
	gets(sa); la = strlen(sa);
	gets(sb); lb = strlen(sb);
	gets(sc); lc = strlen(sc);
	for (i = 0; i < la; i++) ca[sa[i] - 'a']++;
	for (i = 0; i < lb; i++) cb[sb[i] - 'a']++;
	for (i = 0; i < lc; i++) cc[sc[i] - 'a']++;
	for (B = 0; B <= la; B++)
	{
		minC = 1e9;
		for (i = 0; i < 26; i++)
		{
			tC = double(ca[i] - B * cb[i]) / cc[i];
			if (tC < 0.0) break;
			minC = min(minC, tC);
		}
		if (i < 26) break;
		C = (int)minC;
		T = B + C;
		if (T > ansT)
		{
			ansT = T;
			ansB = B;
			ansC = C;
		}
	}
	for (i = 0; i < ansB; i++) printf(sb);
	for (i = 0; i < ansC; i++) printf(sc);
	for (i = 0; i < 26; i++)
		for (j = 0; j < ca[i] - ansB * cb[i] - ansC * cc[i]; j++)
			putchar(i + 'a');
	puts("");
	return 0;
}