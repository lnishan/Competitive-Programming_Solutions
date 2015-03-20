#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_V 101
#define INF 2147483647

using namespace std;

struct edge{ int to, cap, rev; };
vector<edge> g[MAX_V];
int lvl[MAX_V], iter[MAX_V];

void add_edge(int s, int t, int c){
    g[s].push_back( (edge){t, c, g[t].size()} );
    g[t].push_back( (edge){s, c, g[s].size()-1} );
}

int dfs(int s, int t, int f){
    if( s==t ) return f;
    int d;
    for( int &i=iter[s]; i<g[s].size(); i++ )
    {
        edge &e=g[s][i];
        if( e.cap>0 && lvl[s]<lvl[e.to] )
        {
            d=dfs(e.to, t, min(f, e.cap));
            if( d>0 )
            {
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

void bfs(int s){
    int i, a;
    queue<int> q;
    q.push(s);
    memset(lvl, -1, sizeof(lvl));
    lvl[s]=0;
    while( !q.empty() )
    {
        a=q.front();
        for( i=0; i<g[a].size(); i++ )
        {
            edge &e=g[a][i];
            if( lvl[e.to]<0 && e.cap>0 )
            {
                lvl[e.to]=lvl[a]+1;
                q.push(e.to);
            }
        }
        q.pop();
    }
}

int max_flow(int s, int t){
    int f, flow=0;
    while(1)
    {
        bfs(s);
        if( lvl[t]<0 ) break;
        memset(iter, 0, sizeof(iter));
        while( (f=dfs(s, t, INF))>0 )
            flow+=f;
    }
    return flow;
}

int main(){
    int i, n, s, t, e, a, b, c, k=0;
    while( scanf("%d", &n)==1 && n>0 )
    {
        scanf("%d%d%d", &s, &t, &e);
        while( e-- )
        {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
        }
        printf("Network %d\n", ++k);
        printf("The bandwidth is %d.\n\n", max_flow(s, t));
        for( i=1; i<=n; i++ ) g[i].clear();
    }
    return 0;
}
