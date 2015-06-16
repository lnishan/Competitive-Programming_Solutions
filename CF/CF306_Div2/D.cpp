#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char pr[210][210];

void add_edge(int i, int j)
{
	if (i == j) return ;
	if (i > j) swap(i, j);
	if (pr[i][j]) return ;
	pr[i][j] = 1;
}

void remove_edge(int i, int j)
{
	if (i > j) swap(i, j);
	pr[i][j] = 0;
}

void print_ans(int k)
{
	int i, j;
	for (i = 1; i <= 2 * k + 4; i++)
		for (j = i + 1; j <= 2 * k + 4; j++)
			if (pr[i][j])
				printf("%d %d\n", i, j);
}

int main()
{
//	freopen("debug.txt", "w", stdout);
	int i, j, k;
	memset(pr, 0, sizeof(pr));
	cin >> k;
	if (k & 1)
	{
		puts("YES");
		if (k == 1)
			printf("2 1\n1 2\n");
		else
		{
			printf("%d %d\n", 2 * k + 4, (k + 2) * k);
			for (i = 1; i <= k; i++)
				for (j = i + 1; j <= k; j++)
					add_edge(i, j);
			for (i = 1; i < k; i+=2)
				remove_edge(i, i + 1);
			for (i = 1; i < k; i++)
				add_edge(i, 2 * k + 1), add_edge(i, 2 * k + 2);
			add_edge(2 * k + 1, 2 * k + 2);
			for (i = k + 1; i <= (k << 1); i++)
				for (j = i + 1; j <= (k << 1); j++)
					add_edge(i, j);
			for (i = k + 1; i < (k << 1); i += 2)
				remove_edge(i, i + 1);
			for (i = k + 1; i < (k << 1); i++)
				add_edge(i, 2 * k + 3), add_edge(i, 2 * k + 4);
			add_edge(2 * k + 3, 2 * k + 4);
			add_edge(k, 2 * k);
			print_ans(k);
		}
	}
	else
		puts("NO");
}