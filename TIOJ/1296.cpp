#include <iostream>

using namespace std;

int main(){
    int i, n;
    long long int a[20];
    a[1]=1;
    for( i=2; i<20; i++ )
        a[i]=a[i-1]*(4*i-2)/(i+1);
    while( scanf("%d", &n)==1 )
        printf("%I64d\n", a[n]);
    return 0;
}