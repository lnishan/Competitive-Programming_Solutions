#include <iostream>

using namespace std;

int c[32], a[32];

void DFS(int n){
    if( n>31 )
        return ;
    int i, j;
    for( i=0; i<n-1; i++ )
    {
        if( n%(a[i]+a[i+1])==0 )
        {
            for( j=n; j>=i+2; j-- )
                a[j]=a[j-1];
            a[i+1]=n;
            c[n]++;
            DFS(n+1);
            for( j=i+1; j<n; j++ )
                a[j]=a[j+1];
        }
    }
    return ;
}

int main(){
    int i;
    memset(c, 0, sizeof(c));
    a[0]=0; a[1]=1;
    c[1]=1;
    DFS(2);
    for( i=1; i<=31; i++ )
        printf("%d -> %d\n", i, c[i]);
    while(1);
    return 0;
}