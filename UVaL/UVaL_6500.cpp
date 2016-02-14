#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[102][102];
int cnt[102];

int main() {
    int i, j, tt, m, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d%d", &m, &n);
        fill(cnt, cnt + n, 0);
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
                cnt[j] += a[i][j];
            }
        int ans = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++)
                if (a[i][j]) {
                    ans += m - i - cnt[j];
                    --cnt[j];
                }
        }
        printf("%d\n", ans);
    }
    return 0;
}
