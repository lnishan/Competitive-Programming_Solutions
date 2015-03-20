#include <iostream>

using namespace std;

int main(){
    long long int m, n, a;
    while( scanf("%I64d%I64d", &m, &n) && (m!=0||n!=0) )
    {
        a=min(m, n);
        printf("%I64d\n", a*(a+1)*(2*a+1)/6-(m+n+2)*a*(a+1)/2+a*(m*n+m+n+1));
    }
    return 0;
}