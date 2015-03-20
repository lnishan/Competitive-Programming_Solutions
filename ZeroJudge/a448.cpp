#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int i, a, n, m, c[50];
    while( scanf("%d%d", &n, &m)==2 )
    {
        memset(c, 0, sizeof(c));
        while( n-- )
        {
            scanf("%d", &a);
            c[a%m]++;
        }
        for( i=0; i<m; i++ )
        {
            if( i>0 ) putchar(' ');
            printf("%d", c[i]);
        }
        putchar('\n');
    }
    return 0;
}
