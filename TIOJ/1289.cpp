#include <iostream>

using namespace std;

long long int a[2000], f, ans;

int main(){
    int i, j, n, low, mid, high;
    while( scanf("%d", &n)==1 )
    {
        ans=0;
        for( i=0; i<n; i++ )
            scanf("%I64d", &a[i]);
        sort(a, a+n);
        for( i=0; i<n; i++)
            for( j=i+1; j<n; j++ )
            {
                f=a[i]*a[i]+a[j]*a[j];
                low=j+1; high=n;
                while( high-low>1 )
                {
                    mid=(low+high)/2;
                    if( a[mid]*a[mid]<=f )
                        low=mid;
                    else
                        high=mid;
                }
                if( a[low]*a[low]==f )
                    ans++;
            }
        printf("%I64d\n", ans);
    }
    return 0;
}