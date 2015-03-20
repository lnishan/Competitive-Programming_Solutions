#include <iostream>

using namespace std;

long long int pas[20][21], fact[20], r[20], t, flag;

int main(){
    int i, j, n;
    memset(pas, 0, sizeof(pas));
    pas[0][0]=1;
    for( i=0; i<19; i++ )
        for( j=0; j<=i; j++ )
        {
            pas[i+1][j]+=pas[i][j];
            pas[i+1][j+1]+=pas[i][j];
        }
    fact[0]=1;
    for( i=1; i<20; i++ )
        fact[i]=fact[i-1]*i;
    for( i=1; i<20; i++ )
    {
        r[i]=0; flag=1;
        for( j=0; j<=i; j++,flag=-flag )
            r[i]+=fact[i-j]*pas[i][j]*flag;
    }
    while( scanf("%d", &n) && n>0 )
        printf("%I64d\n", r[n]);
    return 0;
}