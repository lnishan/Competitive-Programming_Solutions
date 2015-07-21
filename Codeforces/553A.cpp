#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int N = 2500;
const ull M = 1000000007;

ull c[N][N];

ull cal(int n, int m)
{
	ull &cur = c[n][m];
	if (cur) return cur;
	if (n == m || m == 0) return cur = 1;
	return cur = (cal(n - 1, m - 1) + cal(n - 1, m)) % M;
}

int main()
{
	int i, j;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) c[i][j] = 0;
	ull ans, tot;
	int k, ai;
	scanf("%d", &k);
	scanf("%d", &ai);
	ans = 1;
	tot = ai;
	
	for (i = 1; i < k; i++)
	{
		scanf("%d", &ai);
		ans = (ans * cal(tot + ai - 1, ai - 1)) % M;
		tot += ai;
	}
	printf("%I64u\n", ans);
//	while(1);
	return 0;
}