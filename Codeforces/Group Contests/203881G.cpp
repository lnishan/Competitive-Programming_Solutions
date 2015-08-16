#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    double a, r;
    double co, th;
    cin >> a >> r;
    co = 1 - 0.5 * (a / r) * (a / r);
    th = acos(co);
    printf("%.17f\n", r * r * 0.5 * (th - sqrt(1 - co * co)));
    return 0;
}
