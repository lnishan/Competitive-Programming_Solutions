#include <cstdio>
#include <cstring>

using namespace std;

int a[1001];

int main(){
    int i, t, s, e;
    memset(a, 0, sizeof(a));
    for( i=1; i<=31; i++ )
        a[i*i]=1;
    for( i=2; i<=1000; i++ )
        if( a[i] )
            a[i]=a[i-1]+i;
        else
            a[i]=a[i-1];
    scanf("%d", &t);
    for( i=1; i<=t; i++ )
    {
        scanf("%d%d", &s, &e);
        printf("Case %d: %d\n", i, a[e]-a[s-1]);
    }
    return 0;
}
