#include <iostream>

using namespace std;

int a[10000];
int main(){
    int i, n;
    while( scanf("%d", &n)==1 )
    {
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        sort(a, a+n);
        for( i=0; i<n; i++ )
        {
            if( i>0 ) putchar(' ');
            printf("%d", a[i]);
        }
        putchar('\n');
    }
    return 0;
}