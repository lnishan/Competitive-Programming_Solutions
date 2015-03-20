#include <cstdio>
#include <algorithm>
#define MAX 1005

using namespace std;

int a[MAX];

int main()
{
    int i, j, n, m1, m2, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    if (n == 0)
        printf("%d\n", 0);
    else if (n == 1)
    {
        printf("%d\n", a[0]);
        printf("%d\n", a[0]);
    }
    else if (n == 2)
    {
        printf("%d\n", max(a[0], a[1]));
        printf("%d %d\n", a[0], a[1]);
    }
    else
    {
        sort(a, a+n);
        ans += a[0] + a[1];
        for (i = n-1; i > 3; i-=2)
        {
            m1 = a[i] + a[1] + a[1] + a[0];
            m2 = a[i-1] + a[0] + a[i] + a[0];
            ans += min(m1, m2);
        }
        if (i == 3)
        {
            m1 = a[i] + a[1] + a[1];
            m2 = a[i-1] + a[0] + a[i];
            ans += min(m1, m2);
        }
        else if (i == 2)
            ans += a[i];
        printf("%d\n", ans);

        printf("%d %d\n", a[0], a[1]);
        printf("%d\n", a[0]);
        for (i = n-1; i > 3; i-=2)
        {
            m1 = a[i] + a[1] + a[1] + a[0];
            m2 = a[i-1] + a[0] + a[i] + a[0];
            if (m1 < m2)
            {
                printf("%d %d\n", a[i-1], a[i]);
                printf("%d\n", a[1]);
                printf("%d %d\n", a[0], a[1]);
                printf("%d\n", a[0]);
            }
            else
            {
                printf("%d %d\n", a[0], a[i-1]);
                printf("%d\n", a[0]);
                printf("%d %d\n", a[0], a[i]);
                printf("%d\n", a[0]);
            }
        }
        if (i == 3)
        {
            m1 = a[i] + a[1] + a[1];
            m2 = a[i-1] + a[0] + a[i];
            if (m1 < m2)
            {
                printf("%d %d\n", a[i-1], a[i]);
                printf("%d\n", a[1]);
                printf("%d %d\n", a[0], a[1]);
            }
            else
            {
                printf("%d %d\n", a[0], a[i-1]);
                printf("%d\n", a[0]);
                printf("%d %d\n", a[0], a[i]);
            }
        }
        else if (i == 2)
            printf("%d %d\n", a[0], a[i]);
    }
    return 0;
}
