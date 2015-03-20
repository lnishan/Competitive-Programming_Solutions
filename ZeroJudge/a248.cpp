#include <cstdio>

using namespace std;

int main(){
    long long int a, b;
    int i, n;
    while( scanf("%lld%lld%d", &a, &b, &n)==3 )
    {
        printf("%lld.", a/b);
        a%=b; a*=10;
        for( i=0; i<n; i++ )
        {
            printf("%lld", a/b);
            a%=b; a*=10;
        }
        putchar('\n');
    }
    return 0;
}
