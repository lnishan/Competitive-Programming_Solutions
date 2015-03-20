#include <iostream>

using namespace std;

int main(){
    long long int ten[10], a[10][2], t[10], tc, tmp, cN, n, k, ans;
    int i, j;
    ten[0]=1; for( i=1; i<10; i++ ) ten[i]=ten[i-1]*10;
    a[0][0]=a[0][1]=0;
    for( i=1; i<10; i++ )
    {
        a[i][1]=ten[i-1]*i;
        a[i][0]=a[i][1]; for( j=0; j<i; j++ ) a[i][0]-=ten[j];
    }
    while( scanf("%I64d%I64d", &n, &k)==2 )
    {
        tc=cN=0;
        tmp=n;
        while( tmp>0 )
        {
            t[tc++]=tmp%10;
            tmp/=10;
        }
        ans=a[tc-1][k>0]+a[tc-1][1]*(t[tc-1]-1);
        if( k>0 )
        {
            tmp=n-(cN*10+k)*ten[tc-1]+1;
            if( tmp>ten[tc-1] ) tmp=ten[tc-1];
            if( tmp>0 ) ans+=tmp;
        }
        cN=cN*10+t[tc-1];
        for( i=tc-2; i>=0; i-- )
        {
            ans+=a[i][1]*t[i];
            tmp=n-(cN*10+k)*ten[i]+1;
            if( tmp>ten[i] ) tmp=ten[i];
            if( tmp>0 ) ans+=tmp;
            cN=cN*10+t[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}