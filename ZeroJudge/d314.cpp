#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct treap;
int size(treap *&);

struct treap
{
    int key, pri;
    int sz;
    treap *l, *r;
    treap(): pri(rand()), sz(1), l(NULL), r(NULL){}
    
    void pull()
    {
        sz = size(l) + size(r) + 1;
    }
} *root = NULL;

int size(treap *&t) { return t ? t->sz : 0; }

void split(treap *t, const int &key, treap *&l, treap *&r)
{
    if (!t) { l = r = NULL; return ; }
    if (t->key <= key)
    {
        l = t;
        split(t->r, key, t->r, r);
    }
    else
    {
        r = t;
        split(t->l, key, l, t->l);
    }
    t->pull();
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

void insert(const int &key)
{
    treap *l, *r, *n = new treap;
    n->key = key;
    split(root, key, l, r);
    root = merge(l, n);
    root = merge(root, r);
}

void in(treap *t)
{
    if (!t) return ;
    in(t->l);
    printf("%d(%d) ", t->key, size(t));
    in(t->r);
}

int findKth(treap *t, const int &rk)
{
    int myRk = size(t->l) + 1;
    if (myRk == rk) return t->key;
    else if (myRk < rk)
        return findKth(t->r, rk - myRk);
    else
        return findKth(t->l, rk);
}

int main()
{
    root = NULL;
    int i, n, cnt = 0;
    char s[100], cmd[10];
    while (fgets(s, 100, stdin) && s[0] != 'E')
    {
        if (s[0] == 'G')
        {
            sscanf(s, "%s %d", cmd, &n);
            insert(n);
            cnt++;
        }
        else if (s[0] == 'F')
        {
            sscanf(s, "%s %d", cmd, &n);
            printf("%d\n", findKth(root, cnt - n + 1));
        }
    }
    return 0;
}