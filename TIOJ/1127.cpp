#include <iostream>

using namespace std;

int main(){
    int i, n;
    long long int a[21], b[21];
    a[0]=1; b[0]=0;
    for( i=1; i<=20; i++ )
    {
        a[i]=a[i-1]*3+b[i-1]*2;
        b[i]=a[i-1]+b[i-1];
    }
    while( scanf("%d", &n)==1 )
        printf("%I64d\n", a[n/2]+b[n/2]);
    return 0;
}