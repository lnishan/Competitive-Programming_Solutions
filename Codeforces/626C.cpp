#include <bits/stdc++.h>

using namespace std;

int it2, it3, ans;

char cnt[4500005];

int main() {
    int i, j, n, m;
    scanf("%d%d", &n, &m);
    it2 = n * 2;
    it3 = m * 3;
    ans = max(it2, it3);
    for (i = 1; i <= n; i++) cnt[i * 2]++;
    for (i = 1; i <= m; i++) cnt[i * 3]++;
    for (i = 6; cnt[i] > 1; i += 6) {
        int next2 = it2 + 2, next3 = it3 + 3;
        while (cnt[next2]) next2 += 2;
        while (cnt[next3]) next3 += 3;
        if (next2 <= next3) {
            it2 = next2;
            cnt[it2]++;
            ans = max(ans, it2);
        } else {
            it3 = next3;
            cnt[it3]++;
            ans = max(ans, it3);
        }
    }
    printf("%d\n", ans);
    return 0;
}
