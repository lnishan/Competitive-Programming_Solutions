#include <iostream>

using namespace std;

int main(){
    int a, b, c, d;
    while( scanf("%d", &b)==1 )
    {
        a=b+3;
        c=b*2-5;
        d=(c/10)*10+a%10;
        printf("%d\n", d);
    }
    return 0;
}
