#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

double cal(double a, double r)
{
    double co, th;
    co = 1 - 0.5 * (a / r) * (a / r);
    th = acos(co);
    return r * r * 0.5 * (th - sqrt(1 - co * co));
}

int main()
{
    double a, r1, r2;
    cin >> a >> r1 >> r2;
    printf("%.17f\n", cal(a, r1) + cal(a, r2));
    return 0;
}
