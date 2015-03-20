#include <iostream>

using namespace std;

int a[9], n;

void DFS(int stp){
    int i, j;
    char v;
    if( stp==n )
    {
        for( i=0; i<n; i++ )
            putchar( 48+a[i] );
        putchar('\n');
    }
    for( i=1; i<=n; i++ )
    {
        v=1;
        for( j=0; j<stp; j++ )
            if( a[j]==i )
            {
                v=0;
                break;
            }
        if( v )
        {
            a[stp]=i;
            DFS(stp+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    DFS(0);
    //while(1);
    return 0;
}
