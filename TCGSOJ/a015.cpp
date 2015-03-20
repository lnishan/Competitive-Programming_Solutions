#include <iostream>

using namespace std;

int main(){
    int a, b;
    while( scanf("%d%d", &a, &b)==2 )
        if( a>b )
            printf("%d>%d\n", a, b);
        else if( a==b )
            printf("%d=%d\n", a, b);
        else
            printf("%d<%d\n", a, b);
    return 0;
}
