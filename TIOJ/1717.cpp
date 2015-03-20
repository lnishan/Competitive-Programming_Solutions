#include <iostream>
#include <vector>

using namespace std;

vector<int> r[1001];
char v[1001];
int d[1001], ad[1001], start[1000], sc;

int DFS(int ind){
    if( v[ind] ) return ad[ind];
    int i, s=r[ind].size();
    v[ind]=1;
    ad[ind]=d[ind];
    for( i=0; i<s; i++ )
        ad[ind]=max(ad[ind], DFS(r[ind][i])+d[ind]);
    return ad[ind];
}

int main(){
    int i, j, t, n, rc, ln, ans;
    scanf("%d", &t);
    while( t-- )
    {
        memset(v, 0, sizeof(v));
        sc=ans=0;
        scanf("%d", &n);
        for( i=1; i<=n; i++ )
        {
            scanf("%d%d", &d[i], &rc);
            if( rc==0 ) start[sc++]=i;
            while( rc-- )
            {
                scanf("%d", &ln);
                r[ln].push_back(i);
            }
        }
        for( i=0; i<sc; i++ )
            ans=max(ans, DFS(start[i]));
        printf("%d\n", ans);
        for( i=1; i<=n; i++ )
            r[i].clear();
    }
    return 0;
}
