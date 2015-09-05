#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct treap;
int get_sz(treap *);
struct treap
{
	int val, pri;
	int sz;
	treap *l, *r;
	treap() { pri = rand(); l = r = NULL; sz = 1; }
	void pull()
	{
		sz = get_sz(l) + get_sz(r) + 1;
	}
};
treap *rt = NULL;

int get_sz(treap *t)
{
	return t ? t->sz : 0;
}

void split(treap *t, treap * &l, treap * &r, int val)
{
	if (!t) { l = r = NULL; return ; }
	if (t->val <= val)
	{
		l = t;
		split(t->r, t->r, r, val);
		l->pull();
	}
	else
	{
		r = t;
		split(t->l, l, t->l, val);
		r->pull();
	}
}

void split_k(treap *t, treap * &l, treap * &r, int k)
{
	if (!t) { l = r = NULL; return ; }
	if (get_sz(t->l) < k)
	{
		l = t;
		split_k(t->r, t->r, r, k - get_sz(t->l) - 1);
		l->pull();
	}
	else
	{
		r = t;
		split_k(t->l, l, t->l, k);
		r->pull();
	}
}

treap * merge(treap *l, treap *r)
{
	if (!l) return r;
	if (!r) return l;
	if (l->pri > r->pri)
	{
		l->r = merge(l->r, r);
		l->pull();
		return l;
	}
	else
	{
		r->l = merge(l, r->l);
		r->pull();
		return r;
	}
}

void insert(int val)
{
	treap *l, *r, *t = new treap;
	t->val = val;
	split(rt, l, r, val);
	rt = merge(l, t);
	rt = merge(rt, r);
}

void in(treap *t)
{
	if (!t) return ;
	in(t->l);
	printf("(%d, %d) ", t->val, get_sz(t));
	in(t->r);
}

void pre(treap *t)
{
	if (!t) return ;
	printf("(%d, %d) ", t->val, get_sz(t));
	pre(t->l);
	pre(t->r);
}

void get_del_rk(int k)
{
	treap *l, *r, *ll, *lr;
	split_k(rt, l, r, k);
	treap *t = l;
	while (t->r) t = t->r;
	int ans = t->val;
	printf("%d\n", ans);
	rt = merge(l, r);
	split(rt, l, r, ans);
	split(l, ll, lr, ans - 1);
	lr = merge(lr->l, lr->r);
	l = merge(ll, lr);
	rt = merge(l, r);
}

char s[100];
int main()
{
	int sz = 0;
	srand(134);
	while (gets(s))
	{
		if (strlen(s) == 0) break;
		if (s[0] == '#')
		{
			
			get_del_rk(sz / 2 + 1);
			--sz;
		}
		else
		{
			insert(atoi(s));
			++sz;
//			in(rt); puts("");
//			pre(rt); puts("");
		}
	}
//	insert(2);
//	insert(5);
//	insert(4);
//	insert(1);
//	
//	cout << get_rk(1) << endl;
//	cout << get_rk(4) << endl;
//	
//	del_rk(3);
//	in(rt);
	return 0;
}
