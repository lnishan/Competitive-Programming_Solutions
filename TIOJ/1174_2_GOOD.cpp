#include <iostream>

using namespace std;

int a[100000], b[100000];

int main(){
    int i, i1, i2, n, m, ans;
    scanf("%d%d", &n, &m);
    for( i=0; i<n; i++ ) scanf("%d", &a[i]);
    for( i=0; i<m; i++ ) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+m);
    ans=abs(a[0]-b[0]);
    for( i1=0,i2=0; i1<n && i2<m; )
    {
        ans=min(ans, abs(a[i1]-b[i2]));
        if( a[i1]>b[i2] )
            i2++;
        else
            i1++;
    }
    printf("%d", ans);
    //while(1);
    return 0;
}