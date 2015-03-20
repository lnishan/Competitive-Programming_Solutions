#include <iostream>

using namespace std;

int n, m;
struct arr{
    int aa[100000];
} a[2];

int binSear(int i, int no){
    int low=0, high=(i)?m:n, mid;
    while( high-low>1 )
    {
        mid=(low+high)/2;
        if( a[i].aa[mid]<=no )
            low=mid;
        else
            high=mid;
    }
    return low;
}

int main(){
    int i, p, ans;
    scanf("%d%d", &n, &m);
    for( i=0; i<n; i++ ) scanf("%d", &a[0].aa[i]);
    for( i=0; i<m; i++ ) scanf("%d", &a[1].aa[i]);
    sort(a[0].aa, a[0].aa+n);
    sort(a[1].aa, a[1].aa+m);
    ans=abs(a[0].aa[0]-a[1].aa[0]);
    for( i=0; i<n; i++ )
    {
        p=binSear(1, a[0].aa[i]);
        ans=min(ans, abs(a[0].aa[i]-a[1].aa[p]));
        if( i<n-1 )
            ans=min(ans, abs(a[0].aa[i]-a[1].aa[p+1]));
    }
    for( i=0; i<m; i++ )
    {
        p=binSear(0, a[1].aa[i]);
        ans=min(ans, abs(a[1].aa[i]-a[0].aa[p]));
        if( i<m-1 )
            ans=min(ans, abs(a[1].aa[i]-a[0].aa[p+1]));
    }
    printf("%d", ans);
    while(1);
    return 0;
}