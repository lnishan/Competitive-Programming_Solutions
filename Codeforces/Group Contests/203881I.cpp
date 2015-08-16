#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const int V = 1005;

struct edge { int vi, vj, wt; } ae[500005];
int f[V];

int fF(int i)
{
    return f[i] == i ? i : (f[i] = fF(f[i]));
}

void uF(int i, int j)
{
    f[fF(j)] = fF(i);
}

int main()
{
    int i, j;
    int vi, vj, wt;
    int v, e;
    ll tot = 0, mst = 0;
    scanf("%d%d", &v, &e);
    for (i = 1; i <= v; i++) f[i] = i;
    for (i = 0; i < e; tot += ae[i].wt, i++) scanf("%d%d%d", &ae[i].vi, &ae[i].vj, &ae[i].wt);
    sort(ae, ae + e, [](edge a, edge b){ return a.wt < b.wt; });
    for (i = j = 0; i < e; i++)
    {
        if (fF(ae[i].vi) == fF(ae[i].vj)) continue;
        mst += ae[i].wt;
        uF(ae[i].vi, ae[i].vj);
        ++j;
    }
    if (j < v - 1)
        puts("-1");
    else
        cout << tot - mst;
    return 0;
}
