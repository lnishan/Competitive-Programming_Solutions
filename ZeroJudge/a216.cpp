#include <cstdio>

long long int f[30001], g[30001];

int main(){
    int i, n;
    f[1]=g[1]=1;
    for( i=2; i<=30000; i++ )
        f[i]=f[i-1]+i;
    for( i=2; i<=30000; i++ )
        g[i]=g[i-1]+f[i];
    while( scanf("%d", &n)==1 )
        printf("%lld %lld\n", f[n], g[n]);
    return 0;
}
