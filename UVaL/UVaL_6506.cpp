#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[102];

int main() {
    int i, tt, n;
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    a[5] = 2;
    for (i = 6; i < 102; i++) a[i] = a[i - 1] + a[i - 5];
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        printf("%lld\n", a[n]);
    }
    return 0;
}
