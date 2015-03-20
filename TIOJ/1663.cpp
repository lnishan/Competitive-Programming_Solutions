#include <iostream>

using namespace std;

int main(){
    int t, a, b;
    while( scanf("%d%d%d", &t, &a, &b)==3 )
    {
        if( t==1 )
            printf("%d\n", a+b);
        else if( t==2 )
            printf("%d\n", a-b);
        else if( t==3 )
            printf("%d\n", a*b);
        else
            printf("%d\n", a%b);
    }
    return 0;
}