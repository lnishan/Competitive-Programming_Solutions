#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 10000002;
const int SQ = sqrt(N) + 2;
const int SQQ = sqrt(SQ) + 1e-9;

char *isP;
int *p, pc;
void pre()
{
	int i, j;
	isP = new char[SQ];
	p = new int[SQ];
	pc = 0;
	fill(isP, isP + SQ, 1);
	for (i = 2; i < SQQ; i++)
		if (isP[i])
			for (j = i * i; j < SQ; j += i)
				isP[j] = 0;
	for (i = 2; i < SQ; i++)
		if (isP[i])
			p[pc++] = i;
}

inline int input()
{
	char c;
	for (c = getchar(); c < 48 || c > 57; c = getchar()) ;
	int x = c - 48;
	for (c = getchar(); c > 47 && c < 58; c = getchar()) x = x * 10 + c - 48;
	return x;
}

int main()
{
	int i, j, t, a, c;
	int sq, tmp, ans;
	pre();
	t = input();
	while (t--)
	{
		a = input(); c = input();
		if (c % a)
			puts("NO SOLUTION");
		else
		{
			ans = 1;
			sq = sqrt(c) + 1e-9;
			for (i = 0; i < pc && p[i] <= sq; i++)
				if (c % p[i] == 0)
				{
					tmp = 1;
					for (j = 0; c % p[i] == 0; j++) { c /= p[i]; tmp *= p[i]; }
					while (a % p[i] == 0) { a /= p[i]; j--; }
					if (j) ans *= tmp;
				}
			if (a % c) ans *= c;
			printf("%d\n", ans);
		}
	}
	return 0;

}