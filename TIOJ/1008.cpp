#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

short v1[5000011], v2[5009993];
int n, w, P=2, aP[2]={5000011, 5009993}, ar[2];
struct node{ int n[5]; } tmp;
queue<node> q;

int GCD(int a, int b){
    while( a>0 && b>0 )
        if( a>b )
            a%=b;
        else
            b%=a;
    return (a==0)?b:a;
}

bool check(){
    int i;
    for( i=0; i<n; i++ )
        if( tmp.n[i]==w )
            return true;
    return false;
}

void hash(){
    int i, h=0, n51=1;
    for( i=0; i<n; i++,n51*=51 )
        h+=tmp.n[i]*n51;
    for( i=0; i<P; i++ )
        ar[i]=h%aP[i];
}

int main(){
    int i, j, gcd, cap[5], mcap, stp;
    memset(v1, -1, sizeof(v1));
    memset(v2, -1, sizeof(v2));
    
    scanf("%d", &n);
    scanf("%d", &cap[0]); gcd=cap[0]; mcap=cap[0];
    for( i=1; i<n; i++ )
    {
        scanf("%d", &cap[i]);
        gcd=GCD(gcd, cap[i]);
        mcap=max(mcap, cap[i]);
    }
    scanf("%d", &w);
    if( w>mcap || w%gcd!=0 )
        printf("-1");
    else
    {
        for( i=0; i<n; i++ ) tmp.n[i]=0;
        v1[0]=v2[0]=0;
        q.push(tmp);
        while( !q.empty() )
        {
            for( i=0; i<n; i++ ) tmp.n[i]=q.front().n[i];
            hash();
            stp=max(v1[ar[0]], v2[ar[1]]);
            for( i=0; i<n; i++ )
                if( tmp.n[i]<cap[i] )
                {
                    tmp.n[i]=cap[i];
                    hash();
                    if( v1[ar[0]]<0 || v2[ar[1]]<0 )
                    {
                        v1[ar[0]]=v2[ar[1]]=stp+1;
                        if( check() ) goto ed;
                        q.push(tmp);
                    }
                    tmp.n[i]=q.front().n[i];
                }
            for( i=0; i<n; i++ )
                if( tmp.n[i]>0 )
                {
                    tmp.n[i]=0;
                    hash();
                    if( v1[ar[0]]<0 || v2[ar[1]]<0 )
                    {
                        v1[ar[0]]=v2[ar[1]]=stp+1;
                        if( check() ) goto ed;
                        q.push(tmp);
                    }
                    tmp.n[i]=q.front().n[i];
                }
            for( i=0; i<n; i++ )
                for( j=0; j<n; j++ )
                    if( i!=j )
                    {
                        if( tmp.n[i]+tmp.n[j]>cap[i] )
                        {
                            tmp.n[j]-=(cap[i]-tmp.n[i]);
                            tmp.n[i]=cap[i];
                            hash();
                            if( v1[ar[0]]<0 || v2[ar[1]]<0 )
                            {
                                v1[ar[0]]=v2[ar[1]]=stp+1;
                                if( check() ) goto ed;
                                q.push(tmp);
                            }
                            tmp.n[j]=q.front().n[j];
                            tmp.n[i]=q.front().n[i];
                        }
                        else
                        {
                            tmp.n[i]+=tmp.n[j];
                            tmp.n[j]=0;
                            hash();
                            if( v1[ar[0]]<0 || v2[ar[1]]<0 )
                            {
                                v1[ar[0]]=v2[ar[1]]=stp+1;
                                if( check() ) goto ed;
                                q.push(tmp);
                            }
                            tmp.n[j]=q.front().n[j];
                            tmp.n[i]=q.front().n[i];
                        }
                    }
            q.pop();
        }
        ed:
        printf("%d", max(v1[ar[0]], v2[ar[1]]));
    }
    //while(1);
    return 0;
}
