#include <cstdio>

using namespace std;

int main(){
    int t;
    long long int a, b, c;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if( a==1 )
            printf("%lld\n", b+c);
        else if( a==2 )
            printf("%lld\n", b-c);
        else if( a==3 )
            printf("%lld\n", b*c);
        else if( a==4 )
            printf("%lld\n", b/c);
    }
    return 0;
}
