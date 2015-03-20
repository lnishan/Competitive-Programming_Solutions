/*
f(n)=f(n-1)+4*n-3
f(n)=f(0)+4*(n*(n+1)/2)-3*n=1+2*n*n-n
f(0)=1
*/
#include <iostream>

using namespace std;

int main(){
    int t;
    long long int n;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%I64d", &n);
        printf("%I64d\n", 1+2*n*n-n);
    }
    return 0;
}