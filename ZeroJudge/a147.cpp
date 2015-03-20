#include <cstdio>

int main(){
    int i, n;
    while( scanf("%d", &n)==1 && n>0 )
    {
        for( i=1; i<n; i++ )
            if( i%7>0 )
            {
                if( i>1 ) putchar(' ');
                printf("%d", i);
            }
        putchar('\n');
    }
    return 0;
}
