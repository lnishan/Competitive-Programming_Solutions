#include <iostream>

using namespace std;

int main(){
    int i, j, fact[13], t, n;
    fact[0]=1;
    for( i=1; i<13; i++ )
        fact[i]=fact[i-1]*i;
    
    scanf("%d", &t);
    for( i=1; i<=t; i++ )
    {
        scanf("%d", &n);
        printf("Case #%d:\n", i);
        for( j=0; j<=n; j++ )
            printf("TFCIS%d=%d\n", j, fact[j]);
    }
    return 0;
}