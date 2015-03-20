#include <iostream>

using namespace std;

int main(){
    int i, j, n, m;
    while( scanf("%d%d", &n, &m)==2 )
    {
        for( i=1; i<=n; i++ )
        {
            for( j=1; j<=m; j++ )
            {
                if( j>1 ) putchar(' ');
                printf("%d*%d=%d", i, j, i*j);
            }
            putchar('\n');
        }
    }
    return 0;
}