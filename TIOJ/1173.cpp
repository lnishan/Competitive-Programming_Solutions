#include <iostream>

using namespace std;

int main(){
    int a, b, c, d1, d2;
    double r1, r2;
    scanf("%d%d%d", &a, &b, &c);
    d1=b-a; d2=c-b;
    r1=double(b)/a; r2=double(c)/b;
    if( d1==d2 && r1==r2 )
        printf("both");
    else if( d1==d2 )
        printf("arithmetic");
    else if( r1==r2 )
        printf("geometric");
    else
        printf("normal");
    //while(1);
    return 0;
}