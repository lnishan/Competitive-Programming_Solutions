#include <cstdio>

int main(){
    int i, n, s, c;
    while( scanf("%d", &n)==1 )
    {
        c=0;
        for( i=0; i<n; i++ )
        {
            scanf("%d", &s);
            c+=s;
        }
        if( c>59*n )
            puts("no");
        else
            puts("yes");
    }
    return 0;
}
