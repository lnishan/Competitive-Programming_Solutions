#include <cstdio>
#include <cmath>

using namespace std;

int a[10001], p[5000], pc=0;

int main(){
    int i, j, s, e, c;
    for( i=1; i<=10000; i++ ) a[i]=1;
    for( i=2; i<=100; i++ )
        if( a[i] )
            for( j=i*i; j<=10000; j+=i )
                a[j]=0;
    for( i=2; i<=10000; i++ )
        if( a[i] )
            p[pc++]=i;
    while( scanf("%d%d", &s, &e)==2 )
    {
        c=0;
        for( i=0; i<=e-s; i++ ) a[i]=1;
        for( i=0; p[i]*p[i]<=e && i<pc; i++ )
            for( j=p[i]*(s/p[i]+(s%p[i]!=0)); j<=e; j+=p[i] )
                if( j==p[i] ) continue;
                else a[j-s]=0;
        for( i=0; i<=e-s; i++ ) if( a[i] ) c++;
        if( s==1 ) c--;
        printf("%d\n", c);
    }
    return 0;
}
