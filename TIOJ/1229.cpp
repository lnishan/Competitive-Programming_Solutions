#include <iostream>

using namespace std;

int main(){
    int i, j, l, n, m;
    char s[101], pos[101], a[101], b[101];
    scanf("%d%d%d", &l, &n, &m);
    for( i=1; i<=n; i++ )
        scanf("%d", &pos[i]);
    scanf("\n");
    while( l-- )
    {
        gets(s);
        for( i=1; i<=n; i++ )
            a[i]=s[i-1];
        for( i=0; i<m; i++ )
        {
            for( j=1; j<=n; j++ )
                b[pos[j]]=a[j];
            for( j=1; j<=n; j++ )
                a[j]=b[j];
        }
        for( i=1; i<=n; i++ )
            putchar(a[i]);
        putchar('\n');
    }
    //while(1);
    return 0;
}