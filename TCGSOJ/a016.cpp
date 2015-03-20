#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
        if( n%4!=0 )
            puts("NO");
        else if( n%4==0 && n%100!=0 )
            puts("YES");
        else if( n%100==0 && n%400!=0 )
            puts("NO");
        else
            puts("YES");
    return 0;
}
