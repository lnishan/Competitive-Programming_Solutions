#include <iostream>

using namespace std;

int a[10];
int main(){
    int i, n;
    while( scanf("%d", &n)==1 )
    {
        for( i=0; i<n; i++ ) scanf("%d", &a[i]);
        for( i=n-1; i>=0; i-- )
        {
            printf("%d", a[i]);
            if( i>0 ) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
