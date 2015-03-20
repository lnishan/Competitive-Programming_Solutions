#include <iostream>

using namespace std;

int a[1000000];
char v[1000000];

int main(){
    int i, t, n, cMax, cMin, ans;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d%d", &n, &a[0]);
        cMax=a[0];
        for( i=0; i<=n-1; i++ ) v[i]=0;
        ans=0;
        for( i=1; i<n; i++ )
        {
            scanf("%d", &a[i]);
            if( a[i]>cMax )
            {
                v[i]=1;
                cMax=a[i];
            }
        }
        cMin=a[n-1];
        for( i=n-2; i>=0; i-- )
            if( a[i]<cMin )
            {
                cMin=a[i];
                if( v[i] ) ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}