#include <iostream>

using namespace std;

int main(){
    int i, j, m, p, n, a[100], cpos=0, ct=0;
    scanf("%d%d%d", &m, &p, &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);
    a[n++]=p;
    for( i=0; i<n; )
    {
        if( cpos+m>=a[i] )
            while( cpos+m>=a[i] && i<n )
                i++;
        else
            break;
        cpos=a[i-1];
        ct++;
    }
    if( cpos>=p )
        printf("%d", ct-1);
    else
        printf("IMPOSSIBLE");
    //while(1);
    return 0;
}