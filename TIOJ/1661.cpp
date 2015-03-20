#include <iostream>

using namespace std;

int main(){
    int i, a[100], n, q, i1, i2, t;
    while( scanf("%d", &n)==1 )
    {
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        scanf("%d", &q);
        for( i=0; i<q; i++ )
        {
            scanf("%d%d", &i1, &i2);
            t=a[i1];
            a[i1]=a[i2];
            a[i2]=t;
        }
        printf("%d", a[0]);
        for( i=1; i<n; i++ )
            printf(" %d", a[i]);
        putchar('\n');
    }
    return 0;
}