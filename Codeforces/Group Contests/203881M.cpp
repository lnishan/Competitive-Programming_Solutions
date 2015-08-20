#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
inline int input()
{
    char c;
    for (c = getchar(); c < 48 || c > 57; c = getchar()) ;
    int x = c - 48;
    for (c = getchar(); c > 47 && c < 58; c = getchar()) x = x * 10 + c - 48;
    return x;
}

const int N = 200005;

int a[N];

int sa[N << 2];
int bld_n(int i, int l, int r)
{
    if (l == r) return sa[i] = a[l];
    int m = (l + r) >> 1;
    return sa[i] = max(bld_n(i << 1, l, m), bld_n(i << 1 | 1 , m + 1, r));
}
int qry_n(int i, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) return sa[i];
    if (qr < l || ql > r) return 0;
    int m = (l + r) >> 1;
    return max(qry_n(i << 1, l, m, ql, qr), qry_n(i << 1 | 1, m + 1, r, ql, qr));
}

int sg[N << 2];
void bld_g(int i, int l, int r)
{
    if (l == r) { sg[i] = 0; return ; }
    int m = (l + r) >> 1;
    bld_g(i << 1, l, m); bld_g(i << 1 | 1, m + 1, r);
}
int upd_g(int i, int l, int r, int q, int qg)
{
    if (q < l || q > r) return sg[i];
    if (l == r) return sg[i] = qg;
    int m = (l + r) >> 1;
    return sg[i] = max(upd_g(i << 1, l, m, q, qg), upd_g(i << 1 | 1, m + 1, r, q, qg));
}
int qry_g(int i, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) return sg[i];
    if (qr < l || ql > r) return 0;
    int m = (l + r) >> 1;
    return max(qry_g(i << 1, l, m, ql, qr), qry_g(i << 1 | 1, m + 1, r, ql, qr));
}

int main()
{
    int i, n, m;
    int t, l, r, ans;
    scanf("%d%d", &n, &m);
    a[0] = 0; for (i = 1; i <= n; i++) a[i] = input();
    bld_n(1, 0, n);
    bld_g(1, 0, m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
            ans = qry_n(1, 0, n, l, r);
        else
            ans = qry_g(1, 0, m, l, r);
        upd_g(1, 0, m, i, ans);
        printf("%d\n", ans);
    }
    return 0;
}
