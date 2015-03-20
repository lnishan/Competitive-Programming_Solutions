#include <cstdio>

using namespace std;

int main(){
    int a, b, t=0;
    while( scanf("%d%d", &a, &b)==2 )
    {
        printf("case %d:\n", ++t);
        while( a>0 && b>0 )
            if( a>b )
                a%=b;
            else
                b%=a;
        printf("%d\n", a==0?b:a);
        putchar('\n');
    }
    return 0;
}
