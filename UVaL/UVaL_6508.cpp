#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
const int inf = 1e9;

int a[N];
int pos[N];

int tmp[N];
ll merge_sort(int a[], int l, int r) {
    if (l == r) return 0;
    ll ret;
    int i, j, it = l, m = (l + r) >> 1;
    ret = merge_sort(a, l, m);
    ret += merge_sort(a, m + 1, r);
    for (i = l, j = m + 1; i <= m || j <= r; ) {
        int n1 = i <= m ? a[i] : inf, n2 = j <= r ? a[j] : inf;
        if (n1 < n2) {
            tmp[it++] = n1;
            ++i;
        } else {
            tmp[it++] = n2;
            ++j;
            ret += m - i + 1;
        }
    }
    for (i = l; i <= r; i++) a[i] = tmp[i];
    return ret;
}

int main() {
    int i, j, tt, n, ai;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &ai);
            pos[ai] = i;
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &ai);
            a[i] = pos[ai];
        }
        printf("%lld\n", merge_sort(a, 0, n - 1));
    }
    return 0;
}
