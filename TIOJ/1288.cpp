#include <iostream>

using namespace std;

int a[100][100], dp[100][100];
int main(){
    int i, j, n, ans;
    scanf("%d", &n);
    for( i=0; i<n; i++ )    
        for( j=0; j<=i; j++ )
            scanf("%d", &a[i][j]);
    dp[0][0]=a[0][0];
    for( i=1; i<n; i++ )
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
        dp[i][i]=dp[i-1][i-1]+a[i][i];
        for( j=1; j<i; j++ )
            dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+a[i][j];
    }
    ans=0;
    for( j=0; j<n; j++ )
        ans=max(dp[n-1][j], ans);
    printf("%d", ans);
    //while(1);
    return 0;
}