#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1002;

int a[N];

int main()
{
    int i, j, n, cnt;
    int cur = 0, ans = 0;
    scanf("%d", &n); cnt = n;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    while (cnt)
    {
        if (ans & 1) // backwards
            for (i = n - 1; i >= 0; i--)
            {
                if (used[i]) continue;
                if (cur >= a[i])
                {
                    --cnt;
                    used[i] = 1;
                    ++cur;
                }
            }
        else
            for (i = 0; i < n; i++)
            {
                if (used[i]) continue;
                if (cur >= a[i])
                {
                    --cnt;
                    used[i] = 1;
                    ++cur;
                }
            }
        ans++;
    }
    printf("%d\n", ans - 1);
    return 0;
}
