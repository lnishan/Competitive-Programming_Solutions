#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int L = 5005;

char s[L]; int l, k;
char dp[L][L];

struct node
{
//	char ch; // shouldn't be needed
	int l, r;
	int cnt;
	node *c[2];
	node(): cnt(1) { c[0] = c[1] = NULL; }
} *root = new node;

void cal_dp()
{
	int i, j;
	// even lengths => divider is an invisible bar
	for (i = 0; i < l - 1; i++)
	{
		dp[i][i + 1] = s[i] == s[i + 1];
		if (i - 1 >= 0 && i + 2 < l) dp[i - 1][i + 2] = s[i - 1] == s[i + 2]; 
		for (j = 3; i - j + 1 >= 0 && i + j < l; j++)
			dp[i - j + 1][i + j] = dp[i - j + 3][i + j - 2] && s[i - j + 1] == s[i + j];
	}
	// odd lengths
	for (i = 0; i < l; i++)
	{
		dp[i][i] = 1;
		if (i - 1 >= 0 && i + 1 < l) dp[i - 1][i + 1] = s[i - 1] == s[i + 1];
		for (j = 2; i - j >= 0 && i + j < l; j++)
			dp[i - j][i + j] = dp[i - j + 2][i + j - 2] && s[i - j] == s[i + j];
	}
}

void insert(int ii, int ij)
{
	int i;
	node *t = root;
	for (i = ii; i <= ij; i++)
	{
		char ch = s[i] - 'a';
		if (t->c[ch])
			t->c[ch]->cnt++;
		else
		{
			t->c[ch] = new node;
//			t->c[ch]->ch = s[i]; // shouldn't be needed
			t->c[ch]->l = ii; t->c[ch]->r = i;
		}
		t = t->c[ch];
	}
}

void insert_suf()
{
	int i;
	for (i = 0; i < l; i++)
		insert(i, l - 1);
}

bool pre(node *t)
{
	if (!t) return false;
//	printf("%c %d\n", t->ch, t->cnt);
	if (t != root && dp[t->l][t->r])
		k -= t->cnt;
	if (k <= 0)
	{
		int i;
		for (i = t->l; i <= t->r; i++)
			putchar(s[i]);
		return true;
	}
	if (pre(t->c[0])) return true;
	if (pre(t->c[1])) return true;
	return false;
}

int main()
{
	int i, j;
	gets(s); l = strlen(s);
	scanf("%d", &k);
	cal_dp();
	insert_suf();
	pre(root);
	return 0;
}