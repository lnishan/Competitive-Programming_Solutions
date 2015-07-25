#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define DEBUG(X) cout << #X << " = " << X << '\n';

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int N = 200002;
const int B = 2002;

ull fact[N], fact_inv[N];
pii cord[B];
ull comb[B];

int pw(ull a, int p)
{
	ull ret = 1;
	for ( ; p; p >>= 1, a = (a * a) % MOD)
		if (p & 1)
			ret = (ret * a) % MOD;
	return (int)ret;
}

void pre(int h, int w)
{
	int i;
	fact[0] = 1; fact_inv[0] = 1;
	for (i = 1; i <= (h + w); i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		fact_inv[i] = pw(fact[i], MOD - 2);
	}
}

ull c(ull n, ull m)
{
	return (((fact[n] * fact_inv[m]) % MOD) * fact_inv[n - m]) % MOD;
}

int main()
{
	int i, j;
	int h, w, b;
	int dx, dy;
	ull ans;
	scanf("%d%d%d", &h, &w, &b);
	pre(h, w);
	for (i = 0; i < b; i++)
		scanf("%d%d", &cord[i].first, &cord[i].second);
	sort(cord, cord + b);
	for (i = 0; i < b; i++)
	{
		comb[i] = c(cord[i].first - 1 + cord[i].second - 1, cord[i].first - 1);
		for (j = 0; j < i; j++)
			if (cord[i].first >= cord[j].first && cord[i].second >= cord[j].second)
			{
				dx = cord[i].first - cord[j].first;
				dy = cord[i].second - cord[j].second;
				comb[i] = (comb[i] - (comb[j] * c(dx + dy, dx)) % MOD + MOD) % MOD;
			}
	}
	ans = c(h + w - 2, h - 1);
	for (i = 0; i < b; i++)
	{
		dx = h - cord[i].first;
		dy = w - cord[i].second;
		ans = (ans - (comb[i] * c(dx + dy, dx)) % MOD + MOD) % MOD;
	}
	printf("%d\n", (int)ans);
	return 0;
}