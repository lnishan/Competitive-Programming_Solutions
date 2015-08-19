#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10005;
const double PI = acos(-1);

int n, f;
double a[N];

bool pos(double s)
{
    int i, ret = 0;
    for (i = 0; i < n; i++)
        ret += a[i] / s;
    return ret >= (f + 1);
}

inline double area(double r)
{
    return r * r * PI;
}

int main()
{
    int i, tt;
    double lo, mi, hi, ai;
    scanf("%d", &tt);
    while (tt--)
    {
        lo = hi = 0;
        scanf("%d%d", &n, &f);
        for (i = 0; i < n; i++)
        {
            scanf("%lf", &ai);
            a[i] = area(ai);
            hi = max(hi, a[i]);
        }
        for (i = 0; i < 1000; i++)
        {
            mi = (lo + hi) / 2;
            if (pos(mi))
                lo = mi;
            else
                hi = mi;
        }
        printf("%.17f\n", lo);
    }
    return 0;
}
