#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n<11 )
            printf("%d", n*100);
        else
            printf("%d", (n/11)*1000+(n%11)*100);
    return 0;
}
