#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n%3==0 && n%9!=0 )
            puts("sad");
        else if( n%27==0 )
            puts("sad");
        else
            puts("happy");
    return 0;
}