#include <cstdio>

using namespace std;

unsigned int a[48];

int main(){
    int i, n, t=0;
    a[0]=0; a[1]=1;
    for( i=2; i<48; i++ )
        a[i]=a[i-1]+a[i-2];
    while( scanf("%d", &n)==1 )
    {
        printf("case %d:\n", ++t);
        if( n>=48 )
            puts("overflow");
        else
            printf("%u\n", a[n]);
        putchar('\n');
    }
    return 0;
}
