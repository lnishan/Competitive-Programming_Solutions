#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

struct node
{
    int c, i;
    node() : c(0) {};
    bool operator < (const node &rhs)const
    {
        if (c != rhs.c)
            return c < rhs.c;
        else
            return i > rhs.i;
    }
} a[105];

int main()
{
    int i, j, n, m, vj;
    int v, w;
    scanf("%d%d", &n, &m);
    for (j = 0; j < n; j++) a[j].i = j;
    while (m--)
    {
        v = -1;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &vj);
            if (vj > v)
            {
                v = vj;
                w = j;
            }
        }
        a[w].c++;
    }
    sort(a, a + n);
    printf("%d\n", a[n - 1].i + 1);
    return 0;
}
