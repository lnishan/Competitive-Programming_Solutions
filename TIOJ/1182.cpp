#include <iostream>

using namespace std;

int a[1000];
int main(){
    int i, t, n, sc;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d%d", &n, &sc);
        a[0]=sc; for( i=1; i<n; i++ ) scanf("%d", &a[i]);
        sort(a, a+n);
        for( i=0; i<n-1; i++ )
            if( sc==a[i] )
            {
                n=i;
                break;
            }
        printf("%d %d\n", a[n+1], a[n-1]);
    }
    return 0;
}