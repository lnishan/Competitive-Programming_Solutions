#include <iostream>

using namespace std;

int n, m, a[10];

void DFS(int stp){
    int i;
    if( stp==n )
    {
        for( i=0; i<n; i++ )
            putchar(48+a[i]);
        putchar('\n');
        return ;
    }
    for( i=0; i<=m; i++ )
    {
        a[stp]=i;
        DFS(stp+1);
    }
    return ;
}

int main(){
    scanf("%d%d", &n, &m);
    DFS(0);
    return 0;
}
