#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n>=75 && n<=90 )
            puts("YES");
        else
            puts("NO");
    return 0;
}
