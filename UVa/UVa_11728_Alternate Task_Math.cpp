#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1002;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}; // 11
int ans[N];

int main()
{
//	cout << sizeof(p) / 4 << endl;
	int i, j, ti, t, tt;
	memset(ans, -1, sizeof(ans));
	for (i = 1; i < N; i++)
	{
		t = 1;
		ti = i;
		for (j = 0; j < 11; j++)
		{
			tt = 1;
			while (ti % p[j] == 0)
			{
				tt = tt * p[j] + 1;
				ti /= p[j];
			}
			t *= tt;
		}
		if (ti != 1) t *= (ti + 1);
//		printf("%d %d\n", i, t);
		if (t < N) ans[t] = i;
	}
	int s;
	int cc = 0;
	while (scanf("%d", &s) == 1 && s)
		printf("Case %d: %d\n", ++cc, ans[s]);
	return 0;
}