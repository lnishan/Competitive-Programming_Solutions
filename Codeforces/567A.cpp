#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int a[100005];

int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (i > 0 && i < n - 1)
            printf("%d %d\n", min(a[i] - a[i - 1], a[i + 1] - a[i]), max(a[i] - a[0], a[n - 1] - a[i]));
        else if (i == 0)
            printf("%d %d\n", a[1] - a[0], a[n - 1] - a[0]);
        else
            printf("%d %d\n", a[n - 1] - a[n - 2], a[n - 1] - a[0]);
    }
    return 0;
}
