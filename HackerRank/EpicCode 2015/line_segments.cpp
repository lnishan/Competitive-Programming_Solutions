#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

struct treap
{
	int key, val, pri;
	treap *l, *r;
	treap(): pri(rand()), l(NULL), r(NULL) {}
};
treap *root;

void split(treap *t, const int &key, treap *&l, treap *&r)
{
	if (!t) { l = r = NULL; return ; }
	if (t->key < key)
	{
		l = t;
		split(t->r, key, t->r, r);
	}
	else
	{
		r = t;
		split(t->l, key, l, t->l);
	}
}

treap * merge(treap *l, treap *r)
{
	if (!l) return r;
	if (!r) return l;
	if (l->pri > r->pri)
	{
		l->r = merge(l->r, r);
		return l;
	}
	else
	{
		r->l = merge(l, r->l);
		return r;
	}
}

void insert(int key, int val)
{
	treap *l, *r, *t = new treap;
	t->key = key; t->val = val;
	split(root, key, l, r);
	root = merge(l, t);
	root = merge(root, r);
}

void del(treap *t)
{
	treap *l, *r, *rl, *rr;
	split(root, t->key, l, r);
	split(r, t->key + 1, rl, rr);
	root = merge(l, rr);
}

void in(treap *t)
{
	if (!t) return ;
	in(t->l);
	printf("[%d, %d] ", t->key, t->val);
	in(t->r);
	if (t == root) puts("");
}

treap * collide(int i, int j)
{
	treap *l, *r, *t, *ret = NULL;
	split(root, i, l, r);
	if (r)
	{
		t = r;
		while (t->l) t = t->l;
		if (t->val <= j) ret = t;
	}
	root = merge(l, r);
	return ret;
}

struct itvl { int i, j; } a[100005];

bool cmp(itvl a, itvl b)
{
	return a.j - a.i < b.j - b.i;
}

int main()
{
	int i, n, ans = 0;
	treap *t;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &a[i].i, &a[i].j);
	sort(a, a + n, cmp);
//	for (i = 0; i < n; i++)
//		printf("%d %d\n", a[i].i, a[i].j);
//	in(root);
	for (i = 0; i < n; i++)
		if ( (t = collide(a[i].i, a[i].j)) == NULL )
		{
			++ans;
			insert(a[i].i, a[i].j);
		}
		else
		{
			if (!(t->val + 1 <= a[i].j && collide(t->val + 1, a[i].j) != NULL)) // only overlap 1
			{
//				in(root);
				del(t);
				insert(a[i].i, a[i].j);
			}
		}
	printf("%d\n", ans);
	return 0;
}
