#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

ull p, q;

ull gcd(ull a, ull b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

ull lcm(ull a, ull b)
{
    ull ret = a / gcd(a, b); //  * b;
    return b > (1ULL << 63) / ret ? 0 : ret * b; 
}

int get_pw(ull n, ull b)
{
    int ret = 0;
    for (; n >= b; n /= b) ret++;
    return ret;
}

ull cnt(ull n)
{
    int i, it = min(get_pw(n, p), get_pw(n, q) + 1);
    ull pp = p, qp = 1, ret = 0, lcm1, lcm2;
    for (i = 1; i <= it; i++, pp *= p, qp *= q)
    {
        lcm1 = lcm(pp, qp);
        lcm2 = lcm(pp, qp * q);
        if (lcm1 > n || !lcm1) break;
        ret += n / lcm1 - (lcm2 ? n / lcm2 : 0);
    }
    return ret;
}

int main()
{
    ull l, r;
    cin >> l >> r >> p >> q;
    cout << cnt(r) - cnt(l - 1) << endl;
    return 0;
}
