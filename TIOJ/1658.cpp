#include <iostream>

using namespace std;

int main(){
    int i, j, n, b;
    while( scanf("%d%d", &n, &b)==2 )
    {
        if( b )
            for( i=1; i<=n; i++ )
            {
                for( j=0; j<n-i; j++ ) putchar(' ');
                for( j=0; j<i*2-1; j++ ) putchar('*');
                putchar('\n');
            }
        else
            for( i=1; i<=n; i++ )
            {
                for( j=0; j<n-i; j++ ) putchar(' ');
                if( i==1 ) putchar('*');
                else if( i==n )
                    for( j=0; j<i*2-1; j++ ) putchar('*');
                else
                {
                    putchar('*');
                    for( j=0; j<i*2-3; j++ ) putchar(' ');
                    putchar('*');
                }
                putchar('\n');
            }
    }
    return 0;
}