#include <iostream>
#include <queue>

using namespace std;

int n, sn, en, h[101], f[101], r[101][101], cap[101][101];
char v[101];
queue<int> q;

void label(){
    int i, qi;
    memset(v, 0, sizeof(v));
    q.push(en);
    h[en]=0; v[en]=1;
    while( !q.empty() )
    {
        qi=q.front();
        for( i=1; i<=r[qi][0]; i++ )
            if( !v[r[qi][i]] )
            {
                h[r[qi][i]]=h[qi]+1;
                v[r[qi][i]]=1;
                q.push(r[qi][i]);
            }
        q.pop();
    }
}

int main(){
    int i, rs, s, e, c, qi, mh, mi, tf, ct=0;
    while( scanf("%d", &n) && n>0 )
    {
        for( i=1; i<=n; i++ ){ r[i][0]=0; f[i]=0; }
        memset(cap, 0, sizeof(cap));
        scanf("%d%d%d", &sn, &en, &rs);
        while( rs-- )
        {
            scanf("%d%d%d", &s, &e, &c);
            if( cap[s][e]==0 )
                r[s][ ++r[s][0] ]=e, r[e][ ++r[e][0] ]=s;
            cap[s][e]+=c;
            cap[e][s]+=c;
        }
        label();
        h[sn]=n+1;
        for( i=1; i<=r[sn][0]; i++ )
        {
            f[r[sn][i]]=cap[sn][r[sn][i]];
            cap[sn][r[sn][i]]=0;
            cap[r[sn][i]][sn]*=2;
            if( r[sn][i]!=en ) q.push(r[sn][i]);
        }
        while( !q.empty() )
        {
            qi=q.front();
            while( f[qi]>0 )
            {
                mh=2147483647;
                for( i=1; i<=r[qi][0]; i++ )
                    if( cap[qi][r[qi][i]]>0 && h[r[qi][i]]<mh )
                        mh=h[r[qi][i]], mi=r[qi][i];
                if( mh==2147483647 ) break;
                if( h[qi]>mh )
                {
                    tf=min(f[qi], cap[qi][mi]);
                    f[qi]-=tf;
                    f[mi]+=tf;
                    cap[qi][mi]-=tf;
                    cap[mi][qi]+=tf;
                    if( mi!=sn && mi!=en ) q.push(mi);
                }
                else
                    h[qi]=mh+1;
            }
            q.pop();
        }
        printf("Network %d\n", ++ct);
        printf("The bandwidth is %d.\n\n", f[en]);
    }
    return 0;
}
