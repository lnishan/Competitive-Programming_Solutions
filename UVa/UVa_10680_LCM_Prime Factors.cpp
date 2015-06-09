#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
typedef unsigned long long LLU;

const int N = 1000002;
const int SQ = sqrt(N) + 1e-9;
const LLU R = 1e10;

char isP[N];
LLU mul[N];

void sieve()
{
	int i, j;
	fill(isP, isP + N, 1);
	for (i = 2; i <= SQ; i++)
		if (isP[i])
			for (j = i * i; j < N; j += i)
				isP[j] = 0;
}

void multiply()
{
	LLU i, j;
	fill(mul, mul + N, 1);
	for (i = 2; i < N; i++)
		if (isP[i])
			for (j = i; j < N; j *= i)
				mul[j] *= i;
}

void proc()
{
	int i;
	for (i = 2; i < N; i++)
		mul[i] = (mul[i - 1] * mul[i]) % R;
	for (i = 2; i < N; i++)
	{
		while (mul[i] % 10 == 0) mul[i] /= 10;
		mul[i] %= 10;
	}
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
	int n;
	sieve();
	multiply();
	proc();
	while ((n = input()) && n)
		printf("%llu\n", mul[n]);
	return 0;
}