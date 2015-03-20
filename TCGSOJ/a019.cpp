#include <iostream>

using namespace std;

int main(){
    int a, b;
    while( scanf("%d%d", &a, &b)==2 )
        if( b==2 || b==5 || b==8 )
            puts("200");
        else if( a%2 )
            puts("100");
        else if( a==b )
            puts("50");
        else
            puts("0");
    return 0;
}
