#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1000005;

int v;
vector<int> g[N];
char vst[N];
int lvl[N];
int pr[N];

int find_center(int st)
{
    int i, vi, ret;
    queue<int> q;
    fill(lvl + 1, lvl + 1 + v, -1);
    lvl[st] = 0;
    q.push(st);
    while (!q.empty())
    {
        vi = q.front(); q.pop();
        for (auto &vj: g[vi])
            if (!vst[vj] && lvl[vj] == -1)
            {
                lvl[vj] = lvl[vi] + 1;
                q.push(vj);
            }
    }
    fill(lvl + 1, lvl + 1 + v, -1);
    lvl[vi] = 0;
    pr[vi] = vi;
    q.push(vi);
    while (!q.empty())
    {
        vi = q.front(); q.pop();
        for (auto &vj: g[vi])
            if (!vst[vj] && lvl[vj] == -1)
            {
                lvl[vj] = lvl[vi] + 1;
                pr[vj] = vi;
                q.push(vj);
            }
    }
    ret = vi;
    for (i = 0; i < lvl[vi] / 2; i++)
        ret = pr[ret];
    return ret;
}

void init()
{
    fill(vst + 1, vst + 1 + v, 0);
}

int main()
{
    int i;
    int vi, vj;
    int cen;
    scanf("%d", &v);
    init();
    for (i = 1; i < v; i++)
    {
        scanf("%d%d", &vi, &vj);
        g[vi].push_back(vj);
        g[vj].push_back(vi);
    }
    vi = 1;
    while (1)
    {
        cen = find_center(vi);
        printf("%d\n", cen); fflush(stdout); // my guess
        scanf("%d", &vi); // verdict
        if (vi == 0) break;
        vst[cen] = 1;
    }
    return 0;
}
