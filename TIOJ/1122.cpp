#include <iostream>

using namespace std;

int main(){
    int i, j, k, l, n, a[21][21], s[21][21], ans;
    memset(s, 0, sizeof(s));
    while( scanf("%d%d", &n, &a[1][1])==2 )
    {
        for( i=1; i<=n; i++ )   
            for( j=1; j<=n; j++ )
            {
                if( i!=1 || j!=1 )
                {
                    if( j==1 )
                        a[i][j]=a[1][1]+i;
                    else
                    {
                        a[i][j]=(a[i][j-1]*17)%103;
                        if( (i+j)%2 ) a[i][j]=-a[i][j];
                    }
                }
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            }
        ans=s[1][1];
        for( i=1; i<=n; i++ )
            for( j=1; j<=n; j++ )
                for( k=0; k<i; k++ )
                    for( l=0; l<j; l++ )
                        ans=max(ans, s[i][j]-s[k][j]-s[i][l]+s[k][l]);
        printf("%d\n", ans);
    }
    return 0;
}