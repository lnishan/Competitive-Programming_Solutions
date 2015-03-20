#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n%2 )
            puts("ODD");
        else
            puts("EVEN");
    return 0;
}
