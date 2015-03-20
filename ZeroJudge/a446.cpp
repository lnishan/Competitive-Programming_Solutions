#include <cstdio>

using namespace std;

int main(){
    int i, j, n;
    while( scanf("%d", &n)==1 )
    {
        for( i=1; i<=n; i++ )
        {
            for( j=1; j<=i; j++ )
            {
                if( j>1 ) putchar(' ');
                printf("%d", i*j);
            }
            putchar('\n');
        }
    }
    return 0;
}
