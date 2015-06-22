#include <cstdio>
#include <cstring>
#include <algorithm>
// 19! > 10^16 => to 18 is enough

using namespace std;

typedef unsigned long long int LLU;

const LLU MAX_S = 10000000000000000ULL;

int n;
LLU ans;
LLU a[30];
LLU mx[30][30];
LLU fact[100];

void dfs(int idx, int k, LLU left)
{
	if (left == 0){ ans++; return ; }
	if (idx >= n) return ;
	if (mx[idx][k] < left) return ;
	dfs(idx+1, k, left);
	if (a[idx] <= left)
		dfs(idx+1, k, left-a[idx]);
	if (k > 0 && a[idx] <= 18)
	{
		if (fact[a[idx]] <= left)
			dfs(idx+1, k-1, left - fact[a[idx]]);
	}
}

int main()
{
	int i, j, k;
	LLU S;
	
	ans = 0;
	fact[0] = 1;
	for (i = 1; i <= 18; i++)
		fact[i] = fact[i-1] * i;
	scanf("%d%d%I64u", &n, &k, &S);
	for (i = 0; i < n; i++)
		scanf("%I64u", &a[i]);
	mx[n-1][0] = a[n-1];
	mx[n-1][1] = a[n-1] <= 18 ? fact[a[n-1]] : a[n-1];
	for (i = 2; i <= k; i++) mx[n-1][i] = mx[n-1][1];
	for (i = n-2; i >= 0; i--)
	{
		mx[i][0] = mx[i+1][0] + a[i];
		for (j = 1; j <= k; j++)
		{ 
			mx[i][j] = max(mx[i][j-1], mx[i+1][j] + a[i]);
			if (a[i] <= 18)
				mx[i][j] = max(mx[i][j], mx[i+1][j-1] + fact[a[i]]);
			if (mx[i][j] > MAX_S) mx[i][j] = MAX_S;
		}
	}
	dfs(0, k, S);
	printf("%I64u\n", ans);
	return 0;
}
