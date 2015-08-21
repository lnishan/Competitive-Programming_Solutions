#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t, s, q;
    int x, ans = 0;
    scanf("%d%d%d", &t, &s, &q);
    while (s < t)
    {
        s *= q;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
