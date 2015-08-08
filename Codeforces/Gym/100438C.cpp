#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned long long ull;

const int C = 16;
const ull MOD = 10000 * 10000 * 10 + 7;
const ull INV2 = 10000 * 10000 * 5 + 4;
const int PW = 52;

int c;
ull p[C]; int pw[C];
ull psum[C], ppow[C];
ull psum_inv[C], ppow_inv[C], psum_tot_inv[C];
ull sumA[1 << C], sumB[1 << C], numA[1 << C], numB[1 << C];
int p2[1 << C];
ull inv[PW];

ull ipow(ull a, ull p)
{
	ull ret = 1;
	for ( ; p; p >>= 1, a = (a * a) % MOD)
		if (p & 1)
			ret = (ret * a) % MOD;
	return ret;
}

void pre()
{
	int i, j;
	for (i = 0; i < c; i++)
	{
		psum[i] = 0;
		ull pp = 1;
		for (j = 0; j < pw[i]; pp = (pp * p[i]) % MOD, j++)
			psum[i] = (psum[i] + pp) % MOD;
		ppow[i] = pp % MOD;
		
		psum_inv[i] = ipow(psum[i], MOD - 2);
		ppow_inv[i] = ipow(ppow[i], MOD - 2);
		psum_tot_inv[i] = ipow(psum[i] + ppow[i], MOD - 2);
	}
	for (i = 0; i < PW; i++)
		inv[i] = ipow(i, MOD - 2);
	sumA[0] = sumB[0] = numA[0] = numB[0] = 1;
	for (j = 0; j < c; j++)
	{
		sumA[0] = (sumA[0] * psum[j]) % MOD;
		sumB[0] = (sumB[0] * ppow[j]) % MOD;
		numA[0] = (numA[0] * pw[j]) % MOD;
	}
	for (j = 0; j < c; j++)
		p2[1 << j] = j;
}

int main()
{
	int i, j, t;
	ull self, ans;
	
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &c);
		for (i = 0; i < c; i++)
			scanf("%I64u%d", &p[i], &pw[i]);
		pre();
		self = 1;
		for (i = 0 ; i < c; i++) self = (self * ppow[i]) % MOD;
		ans = (self << 1) % MOD;
		ans = (ans + (sumA[0] * numB[0]) % MOD + (sumB[0] * numA[0]) % MOD) % MOD;
		
		for (i = 1; i < (1 << c); i++)
		{
			j = p2[i & (-i)];
			sumA[i] = (((sumA[i - (i & (-i))] * psum_inv[j]) % MOD) * ppow[j]) % MOD;
			sumB[i] = (((sumB[i - (i & (-i))] * ppow_inv[j]) % MOD) * ((psum[j] + ppow[j]) % MOD)) % MOD;
			numA[i] = (numA[i - (i & (-i))] * inv[pw[j]]) % MOD;
			numB[i] = (numB[i - (i & (-i))] * (pw[j] + 1)) % MOD;
			
			ans = (ans + (sumA[i] * numB[i]) % MOD + (sumB[i] * numA[i]) % MOD) % MOD;
		}
		printf("Case %d: %I64u\n", cas, (ans * INV2) % MOD);
	}
	return 0;
}