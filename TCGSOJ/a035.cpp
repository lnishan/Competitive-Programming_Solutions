#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int i, n, sq;
    char p;
    while( scanf("%d", &n)==1 )
    {
        p=1;
        sq=sqrt(n);
        for( i=2; i<=sq; i++ )
            if( n%i==0 )
            {
                p=0;
                break;
            }
        if( p )
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
