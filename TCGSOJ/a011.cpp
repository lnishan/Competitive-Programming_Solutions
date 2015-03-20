#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n>=60 )
            puts("PASS");
        else
            puts("FAIL");
    return 0;
}
