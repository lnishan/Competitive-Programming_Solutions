#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set> 

using namespace std;

set<int> s;

int main()
{
    int i;
    int n, k, a;
    int m, mi;
    int cnt;
    int nc, oc;
    int p1, p2;
    scanf("%d%d%d", &n, &k, &a);
    cnt = (n + 1) / (a + 1);
    s.insert(0);
    s.insert(n + 1); 
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &mi);
        auto it = s.upper_bound(mi);
        p2 = *it;
        it--;
        p1 = *it;
        oc = (p2 - p1 - 1 + 1) / (a + 1);
        nc = (mi - p1 - 1 + 1) / (a + 1) + (p2 - mi - 1 + 1) / (a + 1);
        cnt -= (oc - nc);
        if (cnt < k) break;
        s.insert(mi);
    }
    if (i > m)
       puts("-1");
    else
        printf("%d\n", i);
    return 0;
}
