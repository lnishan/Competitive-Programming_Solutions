#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 300005;
const int K = 5002;

// k - n % k: n / k
// n % k: n / k + 1
int a[N];
ll sum[N];
ll dp[K][K];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int i, j, n, k, big, sl, bl;
    cin >> n >> k; big = n % k; // small = k - big;
    sl = n / k; bl = n / k + 1;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    sum[0] = 0;
    for (i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i] - a[i - 1];
    for (i = 0; i <= k - big; i++) for (j = 0; j <= big; j++) dp[i][j] = 9e18;
    dp[0][0] = 0;
    for (j = 1; j <= big; j++) dp[0][j] = dp[0][j - 1] + sum[j * bl - 1] - sum[(j - 1) * bl];
    for (i = 1; i <= k - big; i++) dp[i][0] = dp[i - 1][0] + sum[i * sl - 1] - sum [(i - 1) * sl];
    for (i = 1; i <= k - big; i++)
        for (j = 1; j <= big; j++)
            dp[i][j] = min(
                dp[i - 1][j] + sum[i * sl + j * bl - 1] - sum[(i - 1) * sl + j * bl]
                , dp[i][j - 1] + sum[i * sl + j * bl - 1] - sum[i * sl + (j - 1) * bl]);
    cout << dp[k - big][big];
    return 0;
}
