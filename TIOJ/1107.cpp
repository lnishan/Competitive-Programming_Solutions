#include <iostream>

using namespace std;

long long int c[1000001], d[1000001], mn, t, tmp;

int getDgt(long long int n){
    int r=0;
    while( n>0 )
        r++, n/=10;
    return r;
}

int main(){
    int i, n;
    mn=1000000; mn*=1000000;
    c[1]=2; d[1]=1;
    for( i=2; i<=1000000; i++ )
    {
        c[i]=c[i-1]*(4*i-2)/i;
        d[i]=d[i-1]+getDgt(c[i])-getDgt(c[i-1]);
        while( c[i]>mn ) 
            c[i]/=10;
    }
    while( scanf("%d", &n)==1 && n>0 )
    {
        t=c[n]/(n+1);
        tmp=getDgt(c[n])-getDgt(t);
        while( t<mn/10 )
            t*=10;
        printf("%I64d.", t*10/mn);
        printf("%03I64dE+", (t%(mn/10))/100000000+(t%(mn/10000)>=50000000));
        printf("%d\n", d[n]-tmp-1 );
    }
    return 0;
}