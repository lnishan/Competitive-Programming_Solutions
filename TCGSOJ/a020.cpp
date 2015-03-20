#include <iostream>

using namespace std;

int main(){
    int a, b, ans;
    while( scanf("%d%d", &a, &b)==2 )
    {
        ans=0;
        if( b==2 || b==5 || b==8 )
            ans+=200;
        if( a%2 )
            ans+=100;
        if( a==b )
            ans+=50;
        printf("%d\n", ans);
    }
    return 0;
}
