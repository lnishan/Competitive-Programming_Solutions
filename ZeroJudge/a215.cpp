#include <cstdio>

using namespace std;

int main(){
    int i;
    long long int a, b, s;
    while( scanf("%lld%lld", &a, &b)==2 )
    {
        s=a;
        for( i=2; ; i++ )
        {
            if( s>b ) break;
            s+=a+i-1;
        }
        printf("%d\n", i-1);
    }
    return 0;
}
