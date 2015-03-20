#include <iostream>

using namespace std;

int main(){
    long long int a[3];
    while( scanf("%I64d%I64d%I64d", &a[0], &a[1], &a[2])==3 )
    {
        sort(a, a+3);
        if( a[0]+a[1]>a[2] )
            puts("SAFE");
        else
            puts("BYE");
    }
    return 0;
}