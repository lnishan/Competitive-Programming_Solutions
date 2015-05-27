#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef unsigned long long LLU;

const int SQ = 2240;
const int N = 5000002;

char isP[SQ];
int ls[2000], it;
LLU cnt[N];
int arr[N];

int main()
{
	int i, j, k, t, a, b;
	fill(isP, isP + SQ, 1);
	for (i = 2; i < 50; i++)
		if (isP[i])
			for (j = i * i; j < SQ; j += i)
				isP[j] = 0;
	it = 0;
	for (i = 2; i < SQ; i++)
		if (isP[i])
			ls[it++] = i;
	for (i = 1; i < N; i++) arr[i] = i;
	memset(cnt, 0, sizeof(cnt));
	int sq = sqrt(N) + 1e-9;
	for (i = 2; i <= sq; i++)
	{
		int t = arr[i];
		if (t == 1) continue;
		for (j = 0; j < it && t >= ls[j]; j++)
			while (t % ls[j] == 0)
			{
				t /= ls[j];
				cnt[i]++;
			}
		for (j = arr[i] * 2; j < N; j += arr[i])
			while (arr[j] % arr[i] == 0)
			{
				arr[j] /= arr[i];
				cnt[j] += cnt[i];
			}
		arr[i] = 1;
	}
	for (i = 1; i < N; i++)
		cnt[i] += cnt[i-1] + (arr[i] != 1);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a, &b);
		printf("%I64u\n", cnt[a] - cnt[b]);
	}
	return 0;
}
