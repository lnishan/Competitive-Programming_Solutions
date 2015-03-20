#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    while( scanf("%d%d%d", &a, &b, &c)==3 )
        if( a+b==c || a+c==b || b+c==a )
            puts("Good Pair");
        else
            puts("Not Good Pair");
    return 0;
}