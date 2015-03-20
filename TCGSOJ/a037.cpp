#include <iostream>

using namespace std;

int main(){
    int i, j, n;
    scanf("%d", &n);
    for( i=1; i<=n; i++ )
    {
        for( j=0; j<i; j++ )
            putchar(48+i);
        putchar('\n');
    }
    return 0;
}
