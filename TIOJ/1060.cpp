#include <iostream>

using namespace std;

int ah[6]={-1,-1,2,5,5,2};
int h(int y){
    if( y<0 )
        return -1;
    else
        return ah[y%6];
}

int g(int z){
    if( z<=2 )
        return z*z-1;
    else
        return 2;
}

int f(int x){
    if( x>h(x) )
        return f(x-1)-h(x);
    else if( x<h(x) )
        return f(g(x))-g(x);
    else
        return 1;
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d", f(x));
    //while(1);
    return 0;
}