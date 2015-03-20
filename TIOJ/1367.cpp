#include <iostream>

using namespace std;

long long int a[50000], b[50000], ans;

int main(){
    int i, m;
    while( scanf("%d", &m)==1 )
    {
        ans=0;
        for( i=0; i<m; i++ ) scanf("%I64d", &a[i]);
        for( i=0; i<m; i++ ) scanf("%I64d", &b[i]);
        sort(a, a+m);
        sort(b, b+m);
        for( i=0; i<m; i++ )
            ans+=a[i]*b[m-i-1];
        printf("%I64d\n", ans);
    }
    return 0;
}