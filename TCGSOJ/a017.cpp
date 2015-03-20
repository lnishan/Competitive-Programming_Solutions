#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n>=90 )
            puts("A");
        else if( n>=80 )
            puts("B");
        else if( n>=70 )
            puts("C");
        else if( n>=60 )
            puts("D");
        else
            puts("E");
    return 0;
}
