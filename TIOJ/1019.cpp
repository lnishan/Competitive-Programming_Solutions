#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long int dp[1002],d1,d2,t,n,a[1002];

int main(){
    scanf("%I64d",&t);
    for(int it=0;it<t;it++)
    {
        scanf("%I64d",&n);
        for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
        dp[0]=0;
        dp[1]=abs(a[1]-a[0]);
        for(int i=2;i<n;i++)
        {
            d1=dp[i-1]+abs(a[i]-a[i-1]);
            d2=dp[i-2]+abs(a[i]-a[i-2]);
            dp[i]=min(d1,d2);
        }
        printf("%I64d\n",dp[n-1]);
    }
    return 0;
}
