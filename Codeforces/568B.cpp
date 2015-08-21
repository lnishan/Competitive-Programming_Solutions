#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 4005;
const ll MOD = 1e9 + 7;

ll c[N][N];
ll b[N];

ll cal(int n, int m)
{
    ll &cur = c[n][m];
    if (cur) return cur;
    if (m == 0 || m == n) return 1;
    return cur = (cal(n - 1, m - 1) + cal(n - 1, m)) % MOD;
}

int main()
{
    int i, j, n;
//    memset(c, 0, sizeof(c));
    b[0] = 1;
    for (i = 1; i < N; i++)
    {
        b[i] = 0;
        for (j = 0; j < i; j++)
            b[i] = (b[i] + cal(i - 1, j) * b[i - 1 - j]) % MOD;
    }
    scanf("%d", &n);
    printf("%I64d\n", (b[n + 1] - b[n] + MOD) % MOD);
    return 0;
}
