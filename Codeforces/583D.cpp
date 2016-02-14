#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 102;
const int NN = N * N * 2;

int cnt[302];
int a[NN];
vector<int> lis;

int main()
{
    int i, j, n, t, rep, idx;
    int ans = 1, max_cnt = 0;
    scanf("%d%d", &n, &t);
    rep = min(n * 2, t);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (i = 1; i < rep; i++)
        for (j = 0; j < n; j++)
            a[i * n + j] = a[j];
    for (i = 0; i < rep * n; i++)
    {
        if (lis.empty())
            lis.push_back(a[i]);
        else if (a[i] >= lis.back())
            lis.push_back(a[i]);
        else
            *upper_bound(lis.begin(), lis.end(), a[i]) = a[i];
        if (lis.back() == a[i]) max_cnt = max(max_cnt, cnt[a[i]]);
    }
    if (t < n * 2)
        printf("%d\n", (int)lis.size());
    else
        printf("%d\n", (int)lis.size() + (t - n * 2) * max_cnt);
    return 0;
}
