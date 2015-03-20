#include <iostream>

using namespace std;

int main(){
    int i, n, a, mx, mp;
    while( scanf("%d", &n)==1 )
    {
        scanf("%d", &a);
        mx=a; mp=1;
        for( i=2; i<=n; i++ )
        {
            scanf("%d", &a);
            if( a>mx )
            {
                mx=a;
                mp=i;
            }
        }
        printf("%d %d\n", mp, mx);
    }
    return 0;
}
