#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10005

using namespace std;

struct node
{
	int left, right;
} tree[MAX];
int lastchild[MAX]; // last child of i

int si, t, d1, d2, l;
char s[MAX<<1];

void dfs(int d, int par, int nd)
{
	d1=max(d1, d);
	if (lastchild[par] == -1)
		tree[par].left = nd;
	else
		tree[ lastchild[par] ].right = nd;
	lastchild[par] = nd;
	
	while (si < l && s[si++] == 'd')
		dfs(d+1, nd, ++t);
	
	// u
	return ;
}

void getDepth(int d, int idx)
{
	d2=max(d2, d);
	if (tree[idx].left != -1)
		getDepth(d+1, tree[idx].left);
	if (tree[idx].right != -1)
		getDepth(d+1, tree[idx].right);
	return ;
}

int main()
{
	int i, n, cases=0;
	while( gets(s) && s[0]!='#' )
	{
		l=strlen(s);
		n=(l>>1)+1;
		
		// init
		si=0; t=0; d1=0; d2=0;
		for( i=0; i<=n; i++ )
		{
			lastchild[i]=-1;
			tree[i].left=tree[i].right=-1;
		}
		
		// tree construction
		dfs(0, n, 0);
		
		// get new depth
		getDepth(0, 0);
		
		// print ans
		printf("Tree %d: %d => %d\n", ++cases, d1, d2);
	}
	return 0;
}
