#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 100005;
const ll MOD = 1e9 + 7;

int n; ll k;
vector<int> g[N];
ll sz[N];
struct edge { int vi, vj, l, r; }; // len = r - l
edge ae[N];
ll prob[N];
ll psum[N];

int dfs(int vi)
{
    sz[vi] = 1;
    for (auto &vj: g[vi])
        if (!sz[vj])
            sz[vi] += dfs(vj);
    return sz[vi];
}

pll get_sz(edge &e)
{
    if (sz[e.vi] > sz[e.vj])
        return make_pair(sz[e.vj]
            , n - sz[e.vj]);
    else
        return make_pair(sz[e.vi]
            , n - sz[e.vi]);
}

int main()
{
    int i, j, m;
    int vi, vj, l, r;
    ll sum = 0, add, ans = 0, len;
    pll ret;
    cin >> n >> k;
    if (n == 1) { puts("0"); return 0; }
    fill(sz + 1, sz + 1 + n, 0);
    for (i = 0; i < n - 1; i++)
    {
        edge &e = ae[i];
        scanf("%d%d%d%d", &e.vi, &e.vj, &e.l, &e.r);
        g[e.vi].push_back(e.vj);
        g[e.vj].push_back(e.vi);
    }
    dfs(1);
//    for (i = 1; i <= n; i++) cout << sz[i] << endl;
    for (i = 0; i < n - 1; i++)
    {
        ret = get_sz(ae[i]);
        sum += ret.first * ret.second * ae[i].l;
        if (sum > k) break;
    }
//    cout << sum << endl;
    if (sum > k) { puts("0"); return 0; }
    k -= sum;
    for (i = 1; i <= k; i++) prob[i] = 0;
    prob[0] = 1;
    for (i = 0; i < n - 1; i++)
    {
        edge &e = ae[i];
        ret = get_sz(e);
        add = ret.first * ret.second;
        if (add > k) continue;
        len = e.r - e.l;
        for (j = 0; j <= k - add; j++)
            psum[j] = (prob[j] + (j >= add ? psum[j - add] : 0)) % MOD;
        for (m = k; m >= add; m--)
            prob[m] = ((prob[m] + psum[m - add] 
                - (m >= add * (len + 1) ? psum[m - add * (len + 1)] : 0)) % MOD + MOD) % MOD;
    }
    for (i = 0; i <= k; i++) ans = (ans + prob[i]) % MOD;
    cout << ans << endl;
    return 0;
}
