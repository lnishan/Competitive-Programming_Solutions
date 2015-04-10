#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> col[5];
char p[6][6];
char s[6];
int comb[5];
char used[5][100];

int main()
{
	int i, j, k, t, rk;
	scanf("%d", &t);
	while (t--)
	{
		for (j = 0; j < 5; j++)
		{
			col[j].clear();
			fill(used[j]+'A', used[j]+'A'+26, 0);
		}
		scanf("%d", &rk);
		scanf(" ");
		for (i = 0; i < 6; i++)
			gets(p[i]);
		for (i = 0; i < 6; i++)
		{
			gets(s);
			for (j = 0; j < 5; j++)
			{
				if (used[j][s[j]]) continue;
				for (k = 0; k < 6; k++)
					if (s[j] == p[k][j])
					{
						col[j].push_back(s[j]);
						used[j][s[j]] = 1;
						break;
					}
			}
		}
		comb[4] = 1;
		for (i = 3; i >= 0; i--)
			comb[i] = comb[i+1] * col[i+1].size();
		if (rk > comb[0] * col[0].size())
			puts("NO");
		else
		{
			for (j = 0; j < 5; j++) sort(col[j].begin(), col[j].end());
			rk--;
			for (j = 0; j < 5; rk %= comb[j], j++)
				putchar(col[j][rk / comb[j]]);
			puts("");
		}
	}
	return 0;
}
