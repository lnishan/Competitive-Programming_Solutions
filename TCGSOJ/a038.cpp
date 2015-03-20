#include <iostream>

using namespace std;

int main(){
    int i, j, n;
    scanf("%d", &n);
    for( i=1; i<=n; i++ )
    {
        for( j=0; j<n-i; j++ )
            putchar('_');
        for( j=0; j<2*i-1; j++ )
            putchar(48+i);
        putchar('\n');
    }
    //while(1);
    return 0;
}
