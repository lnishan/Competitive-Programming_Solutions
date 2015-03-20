#include <iostream>

using namespace std;

int main(){
    int i, j, k, t[55], tc, T, oc;
    long long int p[51][51], s[51][51], n, ans, tmp;
    memset(p, 0, sizeof(p));
    p[1][1]=1;
    for( i=1; i<50; i++ )
        for( j=1; j<=i; j++ )
        {
            p[i+1][j]+=p[i][j];
            p[i+1][j+1]+=p[i][j];
        }
    for( i=1; i<=50; i++ )
        for( j=i-1; j>=0; j-- )
            p[i][j]+=p[i][j+1];
    for( i=0; i<=50; i++ )
        for( j=0; j<=50; j++ )
            s[i][j]=p[i][j];
    for( i=1; i<=50; i++ )
        for( j=0; j<=i; j++ )
            s[i][j]+=s[i-1][j];
    scanf("%d", &T);
    while( T-- )
    {
        tc=0; ans=0; oc=1;
        scanf("%I64d", &n);
        if( n==1 ){ puts("1"); continue; }
        while( n>0 )
        {
            t[tc++]=n%2;
            n/=2;
        }
        for( i=1; i<tc; i++ )
            ans+=p[i][i/2+1];
        for( i=tc-2; i>0; i-- )
            if( t[i] )
            {
                tmp=tc/2+1-oc;
                if( tmp<0 ) tmp=0;
                ans+=s[i][tmp]; if( tmp==0 ) ans++;
                oc++;
            }
        if( oc>=tc/2+1 ) ans++;
        if( t[0]==1 && oc+1>=tc/2+1 ) ans++;
        printf("%I64d\n", ans);
    }
    return 0;
}