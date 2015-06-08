#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, n, k, ai, t;
	int cnt[2] = {0, 0};
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ai);
		cnt[ai & 1]++;
	}
	t = cnt[1] & 1;
	for (i = 0; i < n - k; i++)
	{
		if (i & 1) // D turn
		{
			if (t)
			{
				if (cnt[1])
					cnt[1]--;
				else
					cnt[0]--;
			}
			else
			{
				if (cnt[0])
					cnt[0]--;
				else
					cnt[1]--;
			}
		}
		else
		{
			if (t) // odd
			{
				if (cnt[0])
					cnt[0]--;
				else
					cnt[1]--;
			}
			else
			{
				if (cnt[1])
					cnt[1]--;
				else
					cnt[0]--;
			}
		}
		t = cnt[1] & 1;
	}
	t = cnt[1] & 1;
	puts(t ? "Stannis" : "Daenerys");
	return 0;
}
