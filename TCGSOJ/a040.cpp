#include <iostream>

using namespace std;

int main(){
    int i, j, n;
    scanf("%d", &n);
    for( i=1; i<=n; i++ )
    {
        for( j=1; j<=n; j++ )
            printf("%dx%d=%2d  ", j, i, i*j);
        putchar('\n');
    }
    //while(1);
    return 0;
}
