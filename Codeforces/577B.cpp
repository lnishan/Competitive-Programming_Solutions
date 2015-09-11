#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 1002;
int cnt[M];
int dp[2][M];

int main()
{
    int i, j, n, m, ai;
    int two, am, flag = 0;
    int z = 0;
    scanf("%d%d", &n, &m);
    fill(cnt, cnt + m, 0);
    fill(dp[0], dp[0] + m, 0); dp[0][0] = 1;
    fill(dp[1], dp[1] + m, 0); dp[1][0] = 1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ai);
        cnt[ai % m]++;
        if (ai == 0) z++;
    }
    if (z) { puts("Yes"); return 0; }
    for (i = 0; i < m; i++)
    {
        if (!cnt[i]) continue;
        
        // decompose
        two = 1;
        while (cnt[i] >= two)
        {
            am = (two * i) % m;
            for (j = 0; j < m; j++) dp[flag][j] = dp[flag ^ 1][j];
            for (j = 0; j < m; j++)
                dp[flag][(j + am) % m] += (dp[flag ^ 1][j] > 0);
            cnt[i] -= two;
            two <<= 1;
            flag ^= 1;
        }
        if (cnt[i])
        {
            am = (cnt[i] * i) % m;
            for (j = 0; j < m; j++) dp[flag][j] = dp[flag ^ 1][j];
            for (j = 0; j < m; j++)
                dp[flag][(j + am) % m] += (dp[flag ^ 1][j] > 0);
            flag ^= 1;
        }
    }
    puts(dp[flag ^ 1][0] > 1 ? "YES" : "NO");
    return 0;
}
