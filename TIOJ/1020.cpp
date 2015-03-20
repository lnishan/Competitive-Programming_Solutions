#include <iostream>

using namespace std;

int a[32], ans[32], N, C=0;

bool cmp(){
    int i;
    for( i=0; i<=N; i++ )
        if( a[i]!=ans[i] )
            return a[i]>ans[i];
}

void DFS(int n){
    int i, j;
    if( n>N )
    {
        C++;
        if( cmp() )
            for( i=0; i<=N; i++ )
                ans[i]=a[i];
        return ;
    }
    for( i=0; i<n-1; i++ )
    {
        if( n%(a[i]+a[i+1])==0 )
        {
            for( j=n; j>=i+2; j-- )
                a[j]=a[j-1];
            a[i+1]=n;
            DFS(n+1);
            for( j=i+1; j<n; j++ )
                a[j]=a[j+1];
        }
    }
    return ;
}

int main(){
    int i;
    memset(ans, 0, sizeof(ans));
    a[0]=0; a[1]=1;
    scanf("%d", &N);
    DFS(2);
    printf("%d\n", C);
    for( i=0; i<=N; i++ )
    {
        if( i>0 ) putchar(' ');
        printf("%d", ans[i]);
    }
    //while(1);
    return 0;
}