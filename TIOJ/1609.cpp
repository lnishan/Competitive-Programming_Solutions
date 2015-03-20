#include <iostream>

using namespace std;

int a[1000000];

int main(){
    int i, n;
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);
    sort(a, a+n);
    for( i=0; i<n; i++ )
    {
        if( i>0 ) putchar(' ');
        printf("%d", a[i]);
    }
    //while(1);
    return 0;
}