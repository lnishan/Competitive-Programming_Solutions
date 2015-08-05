#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct node
{
    ll n;
    int i;
    node() {}
    node(ll _n, int _i) : n(_n), i(_i){}
    bool operator <(const node &rhs)const
    {
        if (n != rhs.n)
            return n < rhs.n;
        else
            return i < rhs.i;
    }
};

node a[200005];
ll t[200005];

int main()
{
    int i, n, k;
    int i1, i2;
    int j1, j2;
    ll m1, m2;
    ll ans = 0;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; a[i].i = i, i++) scanf("%I64d", &a[i].n);
    for (i = 0; i < n; i++) t[i] = a[i].n;
    sort(a, a + n);
    for (i = 1; i < n - 1; i++)
    {
        if (t[i] % k) continue;
        i1 = lower_bound(a, a + n, node(t[i] / k, -1)) - a;
        if (a[i1].n != t[i] / k || (a[i1].n == t[i] / k && a[i1].i >= i)) continue;
        i2 = lower_bound(a, a + n, node(t[i] / k, i)) - a; --i2;
        m1 = i2 - i1 + 1;
        
        i2 = lower_bound(a, a + n, node(t[i] * k, 1e9)) - a; --i2;
        if (a[i2].n != t[i] * k || (a[i2].n == t[i] * k && a[i2].i <= i)) continue;
        i1 = upper_bound(a, a + n, node(t[i] * k, i)) - a;
        m2 = i2 - i1 + 1;
        
        ans += m1 * m2;
    }
    printf("%I64d\n", ans);
    return 0;
}
