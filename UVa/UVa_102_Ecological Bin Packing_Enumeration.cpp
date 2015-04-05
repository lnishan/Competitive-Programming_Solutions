#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

int bin[3][3];
int alloc[3];
char ch[3] = {'B', 'C', 'G'}; // note that we change the input order here

int main()
{
	int i, j, k;
	int ans, tmp;
	int alloc_ans[3];
	while (scanf("%d%d%d", &bin[0][0], &bin[0][1], &bin[0][2]) == 3)
	{
		ans = INF;
		for (i = 1; i < 3; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &bin[i][j]);
		for (i = 0; i < 3; i++)
			swap(bin[i][1], bin[i][2]); // make it in lexicographical order
		alloc[0] = 0; alloc[1] = 1; alloc[2] = 2;
		do
		{
			tmp = 0;
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
					if (j != alloc[i])
						tmp += bin[i][j];
			if (tmp < ans)
			{
				ans = tmp;
				for (i = 0; i < 3; i++)
					alloc_ans[i] = alloc[i];
			}
		} while (next_permutation(alloc, alloc+3));
		for (i = 0; i < 3; i++)
			putchar(ch[alloc_ans[i]]);
		printf(" %d\n", ans);
	}
	return 0;
}
