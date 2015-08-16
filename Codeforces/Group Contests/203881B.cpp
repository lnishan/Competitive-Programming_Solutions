#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

ll s[100005];

int main()
{
    int i, n, q, ai;
    int i1, i2;
    scanf("%d%d", &n, &q);
    fill(s, s + 1 + n, 0);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ai);
        s[i] = s[i - 1] + ai * ((i & 1) * 2 - 1);
    }
    while (q--)
    {
        scanf("%d%d", &i1, &i2);
        printf("%I64d\n", (s[i2] - s[i1 - 1]) * ((i1 & 1) * 2 - 1));
    }
    return 0;
}
