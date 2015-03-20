#include <iostream>

using namespace std;

long long int dp[10001];

int main(){
    int i, j, n, p, a;
    while( scanf("%d%d", &n, &p) && (n!=0||p!=0) )
    {
        dp[0]=1; for( i=1; i<=p; i++ ) dp[i]=0;
        for( i=0; i<n; i++ )
        {
            
            scanf("%d", &a);
            for( j=a; j<=p; j++ )
                dp[j]+=dp[j-a];
        }
        printf("%I64d\n", dp[p]);
    }
    return 0;
}