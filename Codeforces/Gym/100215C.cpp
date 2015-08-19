#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 30005;
const int SQ = 180;

struct seg
{
    vector<int> n;
    char s;
    int all;
    ll sum;
    void print()
    {
        int i;
        if (s)
            for (i = 0; i < n.size(); i++)
                printf("%d ", all);
        else
            for (i = 0; i < n.size(); i++)
                printf("%d ", n[i]);
    }
} s[SQ];


int n, sq, ub;
int a[N];
ll sum;

void build()
{
    int i, j;
    sq = sqrt(n);
    ub = (n - 1) / sq;
    sum = 0;
    for (i = 0; i < ub; i++)
    {
        s[i].s = 0;
        s[i].sum = 0;
        s[i].n.resize(sq);
        for (j = 0; j < sq; s[i].sum += s[i].n[j], j++)
            s[i].n[j] = a[i * sq + j];
        sum += s[i].sum;
    }
    s[ub].s = 0;
    s[ub].sum = 0;
    s[ub].n.resize(n - sq * ub);
    for (j = 0; j < s[ub].n.size(); s[ub].sum += (ll)s[ub].n[j], j++)
        s[ub].n[j] = a[ub * sq + j];
    sum += s[ub].sum;
}

void upd_part(int i, int f, int t, int m)
{
    int j;
    ll osum = s[i].sum;
    if (s[i].s)
       for (j = 0; j < s[i].n.size(); j++)
           s[i].n[j] = s[i].all;
    s[i].s = 0;
    s[i].sum = 0;
    for (j = f; j <= t; j++)
        s[i].n[j] = m;
    for (j = 0; j < s[i].n.size(); j++)
        s[i].sum += (ll)s[i].n[j];
    sum += (s[i].sum - osum);
}

void upd(int f, int t, int m)
{
    int i;
    ll osum;
    int i1 = f / sq, i2 = t / sq;
    if (i1 == i2)
    {
        upd_part(i1, f % sq, t % sq, m);
        return ;
    }
    upd_part(i1, f % sq, s[i1].n.size() - 1, m);
    upd_part(i2, 0, t % sq, m);
    for (i = i1 + 1; i < i2; i++)
    {
        s[i].s = 1;
        s[i].all = m;
        osum = s[i].sum;
        s[i].sum = ll(m) * s[i].n.size();
        sum += (s[i].sum - osum);
    }
}

ll qry_part(int i, int f, int t)
{ 
    if (s[i].s) return ll(s[i].all) * (t - f + 1);
    int j;
    ll ret = 0;
    for (j = f; j <= t; j++)
        ret += (ll)s[i].n[j];
    return ret;
}

ll qry(int f, int t)
{
    int i;
    int i1 = f / sq, i2 = t / sq;
    if (i1 == i2) return qry_part(i1, f % sq, t % sq);
    ll ret = qry_part(i1, f % sq, s[i1].n.size() - 1)
        + qry_part(i2, 0, t % sq);
    for (i = i1 + 1; i < i2; i++)
        ret += (ll)s[i].sum;
    return ret;
}

int main()
{
    freopen("death.in", "r", stdin);
    freopen("death.out", "w", stdout);
    int i, q;
    int f, t;
    ll m, osum, qsum, qlen;
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    build();
    osum = sum;
    while (q--)
    {
        scanf("%d%d", &f, &t); --f; --t;
        if (f > t) swap(f, t);
        if (f < 0 || t >= n) continue;
        qsum = qry(f, t);
        qlen = t - f + 1;
        if (qsum % qlen == 0)
            m = qsum / qlen;
        else
        {
            if (qsum > 0)
                m = qsum / qlen + (sum <= osum);
            else
                m = qsum / qlen - (sum > osum);
        }
        upd(f, t, m);
    }
    for (i = 0; i <= ub; i++)
        s[i].print();
    return 0;
}
