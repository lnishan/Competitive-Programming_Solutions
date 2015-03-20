#include <iostream>

using namespace std;

int main(){
    int a, b;
    while( scanf("%d%d", &a, &b)==2 )
    {
        while( a>0 && b>0 )
            if( a>b )
                a%=b;
            else
                b%=a;
        printf("%d\n", (a==0)?b:a);
    }
    return 0;
}
