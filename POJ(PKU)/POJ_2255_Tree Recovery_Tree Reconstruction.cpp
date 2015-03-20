#include <cstdio>
#include <cstring>
#define MAX 30

using namespace std;

struct node
{
	char ch;
	node *left, *right;
} tree[30];

char pre[MAX], in[MAX];
int iter, pos[128];

void build(int root, int l, int r)
{
	if (l >= r) return ;
	int i;
	node &nr = tree[in[root] - 'A'];
	for (i = 0; i < 2; i++)
	{
		int &p = pos[pre[iter]];
		node &ni = tree[pre[iter] - 'A'];
		if (p < l || p > r) continue ;
		++iter;
		if (p < root)
		{
			nr.left = &ni;
			build(p, l, root-1);
		}
		else
		{
			nr.right = &ni;
			build(p, root+1, r);
		}
	}
}

void traverse(node *root)
{
	if (root->left != NULL) traverse(root->left);
	if (root->right != NULL) traverse(root->right);
	putchar(root->ch);
}

int main()
{
	int i, j, l;
	for (i = 'A'; i <= 'Z'; i++)
		tree[i-'A'].ch = i;
	while (scanf("%s %s", pre, in) == 2)
	{
		for (i = 0; i < 26; i++)
			tree[i].left = tree[i].right = NULL;
		l = strlen(in);
		for (i = 0; i < l; i++)
			pos[in[i]] = i;
		int &root = pos[pre[0]];
		iter = 1;
		build(root, 0, l-1);
		traverse( &tree[pre[0] - 'A'] );
		puts("");
	}
	return 0;
}
