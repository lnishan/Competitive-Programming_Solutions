#include <iostream>
#include <math.h>

using namespace std;

char isP[5001];
int P[2000], pc=0;

int main(){
    int i, j, sq, n;
    sq=sqrt(5000);
    isP[1]=0;
    for( i=2; i<=5000; i++ ) isP[i]=1;
    for( i=2; i<=sq; i++ )
        if( isP[i] )
            for( j=i*i; j<=5000; j+=i )
                isP[j]=0;
    for( i=2; i<=5000; i++ )
        if( isP[i] )
            P[pc++]=i;
    while( scanf("%d", &n)==1 )
    {
        printf("primes between 1 ~ %d:", n);
        for( i=0; i<pc&&P[i]<=n; i++ )
            printf(" %d", P[i]);
        putchar('\n');
    }
    return 0;
}