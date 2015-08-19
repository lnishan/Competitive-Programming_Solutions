#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int f[44];

int get_max(int n)
{
    int i;
    for (i = 43; i; i--)
        if (n % f[i] == 0)
           return n - n / f[i];
    return 0;
}

int main()
{
    freopen("choco.in", "r", stdin);
    freopen("choco.out", "w", stdout);
    int i, m, n;
    f[0] = 1; f[1] = 2;
    for (i = 2; i < 44; i++) f[i] = f[i - 1] + f[i - 2];
    scanf("%d%d", &m, &n);
    printf("%I64u\n", max(get_max(m) * ull(n), ull(m) * get_max(n)));
    return 0;
}
