#include <iostream>

using namespace std;

int a[10001], d[50][3];

int main(){
    int i, j, k, n, t, c, p, ans=0;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d%d%d", &d[i][0], &d[i][1], &d[i][2]);
    scanf("%d", &t);
    for( i=0; i<n; i++ )
    {
        c=1;
        while( d[i][2]>=c )
        {
            p=c*d[i][0];
            for( k=t; k>=p; k-- )
                a[k]=max(a[k], a[k-p]+c*d[i][1]);
            d[i][2]-=c;
            c*=2;
        }
        if( d[i][2]>0 )
        {
            p=d[i][2]*d[i][0];
            for( k=t; k>=p; k-- )
                a[k]=max(a[k], a[k-p]+d[i][2]*d[i][1]);
        }
    }
    for( i=0; i<=t; i++ )
        ans=max(ans, a[i]);
    printf("%d", ans);
    while(1);
    return 0;
}
