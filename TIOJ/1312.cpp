#include <iostream>

using namespace std;

int f[10001];

int getf(int n){
    if( f[n]!=n )
        f[n]=getf(f[n]);
    return f[n];
}

int main(){
    int i, n, m, a, b, k;
    while( scanf("%d%d", &n, &m)==2 )
    {
        for( i=1; i<=n; i++ ) f[i]=i;
        while( m-- )
        {
            scanf("%d%d", &a, &b);
            a=getf(a);
            b=getf(b);
            if( a>b )
                f[a]=b;
            else
                f[b]=a;
        }
        scanf("%d", &k);
        printf("%d\n", getf(k));
    }
    return 0;
}