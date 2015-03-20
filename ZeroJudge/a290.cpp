#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char v[802];
int s, e;
vector<int> r[802];

void dfs( int c ){
    int i, sz=r[c].size();
    if( c==e )
        return ;
    for( i=0; i<sz; i++ )
        if( !v[r[c][i]] )
        {
            v[r[c][i]]=1;
            dfs(r[c][i]);
            if( v[e] ) return ;
        }
    return ;
}

int main(){
    int i, n, m, a, b;
    while( scanf("%d%d", &n, &m)==2 )
    {
        memset(v, 0, sizeof(v));
        for( i=1; i<=n; i++ ) r[i].clear();
        while( m-- )
        {
            scanf("%d%d", &a, &b);
            r[a].push_back(b);
        }
        scanf("%d%d", &s, &e);
        dfs(s);
        if( v[e] )
            puts("Yes!!!");
        else
            puts("No!!!");
    }
    return 0;
}
