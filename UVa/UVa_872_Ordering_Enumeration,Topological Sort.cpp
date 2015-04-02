#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int V = 22;
const int L = 1002;

int v;
char s[L], *ptr;
char used[130];
char ch[V];
int id[130];
char g[V][V];
int path[V];
int cnt;

void dfs(int idx)
{
	int i, j;
	if (idx == v)
	{
		putchar(ch[path[0]]);
		for (i = 1; i < v; i++)
			printf(" %c", ch[path[i]]);
		puts("");
		cnt++;
		return ;
	}
	for (i = 0; i < v; i++)
		if (!used[i])
		{
			for (j = 0; j < idx; j++)
				if (g[i][path[j]]) break;
			if (j == idx)
			{
				used[i] = 1;
				path[idx] = i;
				dfs(idx+1);
				used[i] = 0;
			}
		}
}

int main()
{
	int i, j, t;
	scanf("%d", &t);
	while (t--)
	{
		cnt = 0;
		v = 0;
		memset(g, 0, sizeof(g));
		memset(used, 0, sizeof(used));
		
		scanf(" ");
		gets(s);
		ptr = strtok(s, " ");
		while (ptr)
		{
			used[ptr[0]] = 1;
			ptr = strtok(NULL, " ");
		}
		for (i = 'A'; i <= 'Z'; i++)
			if (used[i])
			{
				id[i] = v;
				ch[v++] = i;
			}
		
		gets(s);
		ptr = strtok(s, " ");
		while (ptr)
		{
			g[ id[ptr[0]] ][ id[ptr[2]] ] = 1;
			ptr = strtok(NULL, " ");
		}
		
		memset(used, 0, sizeof(used));
		dfs(0);
		if (!cnt) puts("NO");
		if (t) puts("");
	}
	return 0;
}
