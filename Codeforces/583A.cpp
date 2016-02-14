#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char r[52], c[52];

int a[2505][2];

int main()
{
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n * n; i++)
        scanf("%d%d", &a[i][0], &a[i][1]);
    for (i = 0; i < n * n; i++)
    {
        if (!r[a[i][0]] && !c[a[i][1]])
        {
            printf("%d ", i + 1);
            r[a[i][0]] = 1;
            c[a[i][1]] = 1;
        }
    }
    return 0;
}
