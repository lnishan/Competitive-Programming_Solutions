#include <iostream>

using namespace std;

int main(){
    int i, j, a, b;
    scanf("%d%d", &a, &b);
    if( a>b )
        for( i=a; i>=b; i-- )
        {
            for( j=0; j<i; j++ )
                putchar('*');
            putchar('\n');
        }
    else
        for( i=a; i<=b; i++ )
        {
            for( j=0; j<i; j++ )
                putchar('*');
            putchar('\n');
        }
    //while(1);
    return 0;
}