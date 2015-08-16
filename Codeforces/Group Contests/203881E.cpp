#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 61;
const int AN = 20005;
const ll MOD = 1e9 + 7;

inline int input()
{
    char c;
    for (c = getchar(); c < 48 || c > 57; c = getchar()) ;
    int x = c - 48;
    for (c = getchar(); c > 47 && c < 58; c = getchar()) x = x * 10 + c - 48;
    return x;
}

char isP[N];
vector<int> plst;
vector<pii> fac[N];

void pre()
{
    int i, j, pp;
    fill(isP, isP + N, 1);
    for (auto i: {2, 3, 5, 7})
        for (j = i * i; j < N; j += i)
            isP[j] = 0;
    for (i = 2; i < N; i++)
        if (isP[i])
            plst.push_back(i);
    for (i = 2; i < N; i++)
        for (j = 0; j < plst.size() && plst[j] <= i; j++)
        {
            if (i % plst[j]) continue;
            fac[i].push_back(make_pair(plst[j], 0));
            for (pp = plst[j]; i % pp == 0; pp *= plst[j])
                fac[i].back().second++;
        }
}

int a[AN];
double mn[AN];
int mn_i[AN];
int cnt[N];
ll ans[AN];

int main()
{
    int i, j, k;
    int n, m;
    int mi;
    pre();
    n = input(); m = input();
    for (i = 1; i <= n; i++) mn[i] = 1e30;
    for (i = 0; i < n; i++) a[i] = input();
    for (i = 0; i < n; i++)
    {
        fill(cnt, cnt + N, 0);
        double lcm = 1;
        for (j = i; j < n; j++)
        {
            for (auto &pr: fac[a[j]])
                if (pr.second > cnt[pr.first])
                {
                    lcm *= pow(pr.first, pr.second - cnt[pr.first]);
                    cnt[pr.first] = pr.second;
                }
            if (lcm < mn[j - i + 1])
            {
                mn[j - i + 1] = lcm;
                mn_i[j - i + 1] = i;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        fill(cnt, cnt + N, 0);
        for (j = mn_i[i]; j < mn_i[i] + i; j++)
            for (auto &pr: fac[a[j]])
                cnt[pr.first] = max(cnt[pr.first], pr.second);
        ans[i] = 1;
        for (j = 0; j < N; j++)
            for (k = 0; k < cnt[j]; k++)
                ans[i] = (ans[i] * j) % MOD;
    }
    while (m--)
    {
        mi = input();
        printf("%I64d\n", ans[mi]);
    }
    return 0;
}
