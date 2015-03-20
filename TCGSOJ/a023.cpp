#include <iostream>

using namespace std;

int main(){
    int i, n;
    while( scanf("%d", &n)==1 )
    {
        for( i=1; ; i++ )
        {
            if( n==1 ) break;
            if( n%2 ) n=3*n+1;
            else n/=2;
        }
        printf("%d\n", i);
    }
    return 0;
}
