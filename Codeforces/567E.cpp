#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

const int V = 100005;
const int E = 100005;
const ll INF = 1e16;

struct full_edge { int vi, vj; ll wt; };
struct edge { int to; ll wt; };
struct sp_edge { int to, id; };

int v, e;
int s, t;

full_edge ae[E];

vector<edge> gf[V], gr[V];
ll df[V], dr[V];

vector<sp_edge> g[V];
int low[V], dfn[V]; int tm = 0;
char eused[E];
char is_bri[E];

struct vert
{
    int vi;
    ll d;
    bool operator <(const vert &rhs)const
    {
        return d > rhs.d;
    }
};
char used[V];
void dijkstra(vector<edge> g[], ll d[], int st)
{
    int i;
    priority_queue<vert> pq;
    fill(d, d + v, INF);
    fill(used, used + v, 0);
    d[st] = 0;
    pq.push( (vert){ st, 0 } );
    while (!pq.empty())
    {
        vert qi = pq.top(); pq.pop();
        if (used[qi.vi]) continue;
        int &vi = qi.vi; ll &di = qi.d;
        for (edge &e: g[vi])
            if (di + e.wt < d[e.to])
            {
                d[e.to] = di + e.wt;
                pq.push( (vert){ e.to, d[e.to] } );
            }
    }
}

int dfs(int vi)
{
    dfn[vi] = tm++;
    low[vi] = dfn[vi];
    for (auto &e: g[vi])
    {
        if (eused[e.id]) continue;
        int &vj = e.to;
        if (dfn[vj] == -1)
        {
            eused[e.id] = 1;
            low[vi] = min(low[vi], dfs(vj));
            if (low[vj] > dfn[vi])
                is_bri[e.id] = 1;
        }
        else
            low[vi] = min(low[vi], dfn[vj]);
    }
    return low[vi];
}

int main()
{
    int i;
    ll sp;
    ll ndd;
    scanf("%d%d%d%d", &v, &e, &s, &t); --s; --t;
    for (i = 0; i < e; i++)
    {
        scanf("%d%d%d", &ae[i].vi, &ae[i].vj, &ae[i].wt); --ae[i].vi; --ae[i].vj;
        gf[ae[i].vi].push_back( (edge){ ae[i].vj, ae[i].wt } );
        gr[ae[i].vj].push_back( (edge){ ae[i].vi, ae[i].wt } );
    }
    dijkstra(gf, df, s);
    dijkstra(gr, dr, t);
//    for (i = 0; i < v; i++) printf("%d %I64d\n", i, dr[i]);
//    for (i = 0; i < v; i++) printf("%d %I64d\n", i, df[i]);
    
    sp = df[t];
    for (i = 0; i < e; i++)
    {
        full_edge &e = ae[i];
        if (df[e.vi] + e.wt + dr[e.vj] == sp)
        {
            g[e.vi].push_back( (sp_edge){ e.vj, i } );
            g[e.vj].push_back( (sp_edge){ e.vi, i } );
        }
    }
    fill(dfn, dfn + v, -1);
    fill(eused, eused + e, 0);
    fill(is_bri, is_bri + e, 0);
    dfs(s);
//    for (i = 0; i < e; i++)
//        if (is_bri[i])
//            printf("%d %d %I64d\n", ae[i].vi, ae[i].vj, ae[i].wt);
    
    for (i = 0; i < e; i++)
    {
        full_edge &e = ae[i];
        if (df[e.vi] + e.wt + dr[e.vj] == sp)
        {
            if (is_bri[i])
                ndd = e.wt;
            else
                ndd = e.wt - 1;
        }
        else
            ndd = sp - df[e.vi] - dr[e.vj] - 1;
        
        if (ndd < 1)
            puts("NO");
        else if (ndd == e.wt)
            puts("YES");
        else
            printf("CAN %I64d\n", e.wt - ndd);
    }
    return 0;
}
