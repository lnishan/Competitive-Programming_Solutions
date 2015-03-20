#include <cstdio>
#include <cstring>
#define MAX 30

using namespace std;

struct node
{
	int left, right;
} tree[MAX];
int order[MAX], iter;
char s[MAX];

void insert(int root, int n)
{
	if (n < root)
	{
		if (tree[root].left == -1)
			tree[root].left = n;
		else
			insert(tree[root].left, n);
	}
	else
	{
		if (tree[root].right == -1)
			tree[root].right = n;
		else
			insert(tree[root].right, n);
	}
}

void dfs(int idx)
{
	putchar(idx + 'A');
	if (tree[idx].left != -1)
		dfs(tree[idx].left);
	if (tree[idx].right != -1)
		dfs(tree[idx].right);
	return ;
}

int main()
{
	int i, j, k, l, root;
	while (1)
	{
		//init
		iter=-1;
		for (i = 0; i < MAX; i++ )
			tree[i].left = tree[i].right = -1;
		
		while ( gets(s) && s[0]!='*' && s[0]!='$' )
		{
			l = strlen(s);
			for (i = l-1; i >= 0; i-- )
				order[++iter] = s[i]-'A';
		}
		
		// tree construction
		root = order[iter];
		for (iter=iter-1; iter>=0; iter-- )
			insert(root, order[iter]);
		
		// preorder traversal
		dfs(root);
		puts("");
		
		if (s[0] == '$')
			break;
	}
	return 0;
}
