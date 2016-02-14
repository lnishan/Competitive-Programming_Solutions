#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1e5 + 2;

int a[N], b[N];
int dp[N][3];

int main() {
    int i, tt, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        for (i = 0; i < n; i++) scanf("%d", &b[i]);
        dp[0][0] = 0;
        dp[0][1] = a[0];
        dp[0][2] = b[0];
        for (i = 1; i < n; i++) {
            dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];
        }
        int ans = max(dp[n - 1][1], dp[n - 1][2]);
        ans = max(ans, dp[n - 1][0]);
        printf("%d\n", ans);
    }
    return 0;
}
