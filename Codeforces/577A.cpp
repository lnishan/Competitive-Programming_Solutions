#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int i, n, x, sqx;
    long long ans = 0;
    cin >> n >> x;
    sqx = sqrt(x) + 1e-6;
    for (i = 1; i <= min(sqx, n); i++)
    {
        if (x % i == 0 && x / i <= n) ans += 2;
        if (i * i == x) --ans;
    }
    cout << ans;
    return 0;
}
