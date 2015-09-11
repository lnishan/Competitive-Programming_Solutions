#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
    int x, y, i;
} a[1000006];

int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; a[i].i = i, a[i].x /= 1000, i++) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a, a + n, 
        [](node a, node b)
        {
            return a.x != b.x ? a.x < b.x
                : (a.x % 2 ? a.y < b.y : a.y > b.y);
        } );
    for (i = 0; i < n; i++)
        printf("%d ", a[i].i + 1);
    return 0;
}
