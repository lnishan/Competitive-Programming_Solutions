#include <iostream>

using namespace std;

int main(){
    int i, a, b, ans;
    while( scanf("%d%d", &a, &b)==2 )
    {
        printf("%d", a);
        ans=a;
        if( a<=b )
            for( i=a+1; i<=b; i++ )
            {
                printf("+%d", i);
                ans+=i;
            }
        else
            for( i=a-1; i>=b; i-- )
            {
                printf("+%d", i);
                ans+=i;
            }
        printf("=%d\n", ans);
    }
    return 0;
}
