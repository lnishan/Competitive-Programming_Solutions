#include <iostream>

using namespace std;

int main(){
    char a[11][11];
    int i, j, n, dp[11][11];
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for( i=1; i<=n; i++ )
        for( j=1; j<=n; j++ )
            cin>>a[i][j];
    for( i=1; i<=n; i++ ){ a[i][0]='X'; a[0][i]='X'; }
    for( i=1; i<=n; i++ )
        for( j=1; j<=n; j++ )
            if( a[i][j]=='X' )
                dp[i][j]=0;
            else 
            {
                if( a[i-1][j]=='X' && a[i][j-1]=='X' && a[i][j]!='A' )
                {
                    dp[i][j]=0;
                    a[i][j]='X';
                }
                else
                {
                    if( a[i][j]=='A' || a[i][j]=='B' )
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j]-48;
                }
            }
    if( a[n][n]=='X' ) printf("X"); else printf("%d", dp[n][n]);
    //while(1);
    return 0;
}