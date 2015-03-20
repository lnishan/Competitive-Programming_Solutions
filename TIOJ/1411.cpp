#include <iostream>

using namespace std;

int a[2000001][2];

int main(){
    int i, n, sum, msum, misum, ans;
    long long int t;
    while( scanf("%d", &n)==1 )
    {
        for( i=-n; i<=n; i++ ) a[i+1000000][0]=-2; a[1000000][0]=a[1000000][1]=-1;
        sum=ans=0; msum=-1000001; misum=1000001;
        for( i=0; i<n; i++ )
        {
            scanf("%I64d", &t);
            if( t>0 ) t=1; else if( t==0 ) t=0; else t=-1;
            sum+=t;
            msum=max(msum, sum);
            misum=min(misum, sum);
            if( a[sum+1000000][0]<-1 )
                a[sum+1000000][0]=a[sum+1000000][1]=i;
            else
                a[sum+1000000][1]=i;
        }
        for( i=misum; i<=msum; i++ )
            ans=max(ans, a[i+1000000][1]-a[i+1000000][0]);
        printf("%d\n", ans);
    }
    return 0;
}