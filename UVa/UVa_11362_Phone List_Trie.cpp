#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
	char val;
	char end;
	node *c[10];
	node(){}
	node(char _val, char _end): val(_val), end(_end)
	{
		int i;
		for (i = 0; i < 10; i++)
			c[i] = NULL;
	}
} *root;

void del(node *t)
{
	int i;
	if (!t) return ;
	for (i = 0; i < 10; i++)
	{
		del(t->c[i]);
		t->c[i] = NULL;
	}
	delete t;
}

void init()
{
	int i;
	del(root);
	root = new node;
	root->end = 0;
	for (i = 0; i < 10; i++) root->c[i] = NULL;
}

bool insert(node *t, const char *s, const int &len, const int &i, const char &nnd)
{
	bool ret = t->end;
	if (i == len) { t->end = 1; return nnd ? ret : 1; }
	int n = s[i] - '0';
	if (t->c[n])
		ret = max(ret, insert(t->c[n], s, len, i + 1, nnd));
	else
	{
		t->c[n] = new node(n, i == len - 1);
		if (i < len - 1)
			ret = max(ret, insert(t->c[n], s, len, i + 1, 1));
	}
	return ret;
}

int main()
{
	char s[12];
	int i, t, n, l;
	char flag;
	scanf("%d", &t);
	while (t--)
	{
		init();
		flag = 1;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf(" ");
			gets(s);
			l = strlen(s);
			while (s[l - 1] == ' ') --l;
			if (insert(root, s, l, 0, 0))
				flag = 0;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}