#include <iostream>

using namespace std;

long long int dp[51][50];
int a[50],n,i,j,k;

int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i>1) dp[3][i-2]=a[i]*a[i-1]*a[i-2];
    }
    for(i=4;i<=n;i++)
        for(j=0;j<=n-i;j++)
        {
            dp[i][j]=min(dp[i-1][j+1]+a[j]*a[j+1]*a[j+i-1],dp[i-1][j]+a[j]*a[j+i-2]*a[j+i-1]);
            for(k=3;k<=i-2;k++)
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k+1][j+k-1]+a[j]*a[j+k-1]*a[j+i-1]);
        }
    printf("%lld",dp[n][0]);
    return 0;
}
