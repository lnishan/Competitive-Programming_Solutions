#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200005;

int f[N];
char seg[N << 2];

int findF(int i)
{
    return f[i] == i ? i : (f[i] = findF(f[i]));
}

void uniF(int i, int j)
{
    int fi = findF(i), fj = findF(j);
    f[fj] = fi;
}

void upd(int i, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r) return ;
    if (ql <= l && r <= qr)
    {
        if (!seg[i])
        {
            seg[i] = 1;
            for (int j = l; j <= r; j++) uniF(ql, j);
        }
        uniF(ql, l);
        return ;
    }
    int m = (l + r) >> 1;
    upd(i << 1, l, m, ql, qr);
    upd(i << 1 | 1, m + 1, r, ql, qr);
}

int main()
{
    int i;
    int n, q;
    int cmd, x, y;
    scanf("%d%d", &n, &q);
    fill(seg + 1, seg + 1 + (n << 2), 0);
    for (i = 0; i < n; i++) f[i] = i;
    while (q--)
    {
        scanf("%d%d%d", &cmd, &x, &y); --x; --y;
        if (x > y) swap(x, y);
        if (cmd == 1)
            uniF(x, y);
        else if (cmd == 2)
            upd(1, 0, n - 1, x, y);
        else // 3
            puts(findF(x) == findF(y) ? "YES" : "NO");
    }
    return 0;
}
