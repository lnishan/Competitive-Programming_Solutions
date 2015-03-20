#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int i, n, a[100];
    while( scanf("%d", &n)==1 )
    {
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        sort(a, a+n);
        if( n%2 )
            printf("%d\n", a[n/2]);
        else
            printf("%d\n", (a[n/2-1]+a[n/2])/2);
    }
    return 0;
}
