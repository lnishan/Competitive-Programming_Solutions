#include <iostream>

using namespace std;

int main(){
    int i, n, r, ans;
    while( scanf("%d%d", &n, &r)==2 )
    {
        ans=1;
        for( i=0; i<r; i++ )
            ans*=(n-i);
        printf("%d\n", ans);
    }
    return 0;
}
