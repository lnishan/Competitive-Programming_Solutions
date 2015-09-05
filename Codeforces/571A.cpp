#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

inline ll h3(int m)
{
    return m < 0 ? 0 : (ll)(m + 2) * (m + 1) / 2;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int i, a, b, c, d, tot;
    int da, db, dc;
    ll ans = 0;
    cin >> a >> b >> c >> d;
    tot = a + b + c;
    for (i = 0; i <= d; i++, tot++)
    {
        da = (tot + 1) / 2 - a;
        db = (tot + 1) / 2 - b;
        dc = (tot + 1) / 2 - c;
        if (da <= 0 || db <= 0 || dc <= 0) continue;
        ans += h3(i)
            - h3(i - da) - h3(i - db) - h3(i - dc)
            + h3(i - da - db) + h3(i - da - dc) + h3(i - db - dc)
            - h3(i - da - db - dc);
    }
    cout << ans;
    return 0;
}
